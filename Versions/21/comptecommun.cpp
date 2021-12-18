/* comptecommun.cpp
 * version 18
 * H. Iopeti, univ. Lorraine
 */

#include "comptecommun.hpp"
#include "ui_comptecommun.h"

// Constructeur de la classe CompteCommun.
CompteCommun::CompteCommun(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompteCommun)
{
    ui->setupUi(this);
}

// Constructeur de la classe CompteCommun.
//
// QWidget parent
// Compte le compte
CompteCommun::CompteCommun(QWidget* parent, const std::string compte, const GestionnaireDialogue& gd)
    : QDialog(parent)
    , ui(new Ui::CompteCommun)
    , gestionnaire(gd)
    , compte(compte)
{
    ui->setupUi(this);
    ui->nomDuCompte->setText(compte.c_str());
    ui->typeDuCompte->setText("Compte Commun");

    std::string liste_membres_concat;
    std::vector<std::string> liste_membres = gestionnaire.getGestionnaireBDD().recuperer_liste_membres(compte);
    for(int i = 0; i < (int)liste_membres.size() - 1 ; ++i){
        liste_membres_concat.append(gestionnaire.getGestionnaireBDD().recherche_utilisateur(liste_membres[i].c_str()).get_nom_utilisateur()).append(", ");
    }
    liste_membres_concat.append(gestionnaire.getGestionnaireBDD().recherche_utilisateur(liste_membres[liste_membres.size() - 1].c_str()).get_nom_utilisateur().append("."));

    ui->membresDuCompte->setText(liste_membres_concat.c_str());

    raffraichir_affichage();
}

//Destructeur de la classe CompteCommun.
CompteCommun::~CompteCommun()
{
    delete ui;
}

// La procédure associée à un clic de bouton retour.
void CompteCommun::on_retour_clicked()
{
    this->reject(); // On ferme la fenêtre de dialogue.
}

// La procédure associée à un clic de bouton retirer de l'argent.
//
// version 20 Hugo Iopeti, univ. Lorraine
void CompteCommun::on_retirerDeLArgent_clicked()
{
    QString montant = ui->Montant->toPlainText(); //On récupère le montant rentré par l'utilisateur.
    time_t now = time(nullptr); //On génère l'id d'un transaction avec le temps actuel en millisecondes.
    gestionnaire.getGestionnaireBDD().ajouter_transaction(now, compte, "NULL", gestionnaire.get_utilisateur_connecte().get_adresse_mail(), -montant.toInt());
    raffraichir_affichage();
}

// La procédure associée à un clic de dépot d'argent.
//
// version 20 Hugo Iopeti, univ. Lorraine
void CompteCommun::on_deposerDeLArgent_clicked()
{
    QString montant = ui->Montant->toPlainText(); //On récupère le montant rentré par l'utilisateur.
    time_t now = time(nullptr); //On génère l'id d'un transaction avec le temps actuel en millisecondes.
    gestionnaire.getGestionnaireBDD().ajouter_transaction(now, compte, gestionnaire.get_utilisateur_connecte().get_adresse_mail(), "NULL", montant.toInt());
    raffraichir_affichage();
}

// La procédure qui raffraichit l'affichage d'un compte commun.
//
// version 20 Hugo Iopeti, univ. Lorraine
void CompteCommun::raffraichir_affichage(){
    std::string liste_transactions_concat;
    std::vector<std::string> liste_transactions = gestionnaire.getGestionnaireBDD().recuperer_liste_transactions(compte);

    int montant_total = 0;
    for(int i = 0 ; i < (int)liste_transactions.size(); ++i){
        QStringList liste = QString(liste_transactions[i].c_str()).split(" ");
        int montant = atoi(liste[2].toStdString().c_str());
        std::string utilisateur;
        //On gère l'affichage selon si l'utilisateur dépose ou retire de l'argent.
        if(montant > 0) {
        utilisateur = gestionnaire.getGestionnaireBDD().recherche_utilisateur(liste[0]).get_nom_utilisateur();
        liste_transactions_concat.append("- ").append(utilisateur).append(" a déposé ").append(std::to_string(montant)).append("€.\n");
        }
        else  {
        utilisateur = gestionnaire.getGestionnaireBDD().recherche_utilisateur(liste[1]).get_nom_utilisateur();
        liste_transactions_concat.append("- ").append(utilisateur).append(" a retiré ").append(std::to_string(-montant)).append("€.\n");
        }
        montant_total += montant; //On calcul le solde d'un compte commun.
    }
    ui->Liste->setText(liste_transactions_concat.c_str());

    std::string solde = std::to_string(montant_total).append("€");
    ui->soldeDuCompte->setText(solde.c_str()); //On affiche le solde d'un compte commun.
}
