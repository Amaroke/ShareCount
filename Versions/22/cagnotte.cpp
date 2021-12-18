/* cagnotte.cpp
 * version 18
 * L. Yvoz, univ. Lorraine
 */

#include "cagnotte.hpp"
#include "ui_cagnotte.h"

Cagnotte::Cagnotte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cagnotte)
{
    ui->setupUi(this);
}

// Constructeur de la classe Cagnotte.
//
// QWidget parent
// Compte le compte
// gd gestionnaire de dialogue
Cagnotte::Cagnotte(QWidget* parent, const std::string compte, const GestionnaireDialogue& gd)
    : QDialog(parent)
    , ui(new Ui::Cagnotte)
    , gestionnaire(gd)
    , compte(compte)
{
    ui->setupUi(this);
    ui->nomDuCompte->setText(compte.c_str());
    ui->typeDuCompte->setText("Cagnotte");

    Utilisateur createur = gestionnaire.getGestionnaireBDD().recherche_createur(compte.c_str());

    //On enleve le bouton permettant de retirer de l'argnet de l'affichage si l'utilisateur actuel n'est pas le créateur du compte.
    if (std::strcmp(createur.get_adresse_mail().c_str(), gestionnaire.get_utilisateur_connecte().get_adresse_mail().c_str()) != 0) {
        ui->retirerDeLArgent->hide();
    }

    ui->createurDuCompte->setText(createur.get_nom_utilisateur().c_str());

    raffraichir_affichage();
}

// La procédure associée à un clic de bouton retour.
void Cagnotte::on_retour_clicked()
{
    this->reject(); // On ferme la fenêtre de dialogue.
}

// La procédure associée à un clic de bouton retirer de l'argent.
void Cagnotte::on_retirerDeLArgent_clicked()
{
    QString montant = ui->Montant->toPlainText(); //On récupère le montant rentré par l'utilisateur.
    int montant_total = raffraichir_affichage();
    if (montant.toInt() <= montant_total) {
        time_t now = time(nullptr); //On génère l'id d'une transaction avec le temps actuel en millisecondes.
        gestionnaire.getGestionnaireBDD().ajouter_transaction(now, compte, "NULL", gestionnaire.get_utilisateur_connecte().get_adresse_mail(), -montant.toInt());
        raffraichir_affichage();
    } else {
        //MESSAGE D'ERREUR A ECRIRE DANS UNE FENETRE D'ALERTE
        std::cout << "Impossible de retirer plus d'argent que contenu dans la cagnotte";
        fflush(stdout);
    }
}

// La procédure associée à un clic de dépot d'argent.
void Cagnotte::on_deposerDeLArgent_clicked()
{
    QString montant = ui->Montant->toPlainText(); //On récupère le montant rentré par l'utilisateur.
    time_t now = time(nullptr); //On génère l'id d'une transaction avec le temps actuel en millisecondes.
    gestionnaire.getGestionnaireBDD().ajouter_transaction(now, compte, gestionnaire.get_utilisateur_connecte().get_adresse_mail(), "NULL", montant.toInt());
    raffraichir_affichage();
}

// La procédure qui raffraichit l'affichage de la cagnotte.
//
// le montant total d'argent dans la cagnotte
int Cagnotte::raffraichir_affichage(){
    std::string liste_transactions_concat;
    std::vector<std::string> liste_transactions = gestionnaire.getGestionnaireBDD().recuperer_liste_transactions(compte);

    int montant_total = 0;
    for(int i = 0 ; i < (int)liste_transactions.size(); ++i){
        QStringList liste = QString(liste_transactions[i].c_str()).split(" ");
        int montant = atoi(liste[2].toStdString().c_str());
        std::string utilisateur;
        //On gère l'affichage selon si l'utilisateur dépose ou retire de l'argent.
        if (montant > 0) {
            utilisateur = gestionnaire.getGestionnaireBDD().recherche_utilisateur(liste[0]).get_nom_utilisateur();
            liste_transactions_concat.append("- ").append(utilisateur).append(" a donné ").append(std::to_string(montant)).append("€.\n");
        } else  {
            utilisateur = gestionnaire.getGestionnaireBDD().recherche_utilisateur(liste[1]).get_nom_utilisateur();
            liste_transactions_concat.append("- ").append(utilisateur).append(" a retiré ").append(std::to_string(-montant)).append("€.\n");
        }
        montant_total += montant; //On calcule le solde de la cagnotte.
    }
    ui->Liste->setText(liste_transactions_concat.c_str());

    std::string solde = std::to_string(montant_total).append("€");
    ui->soldeDuCompte->setText(solde.c_str()); //On affiche le solde d'un compte commun.
    return montant_total;
}

// Destructeur de la classe, ne fait rien.
Cagnotte::~Cagnotte()
{
    delete ui;
}
