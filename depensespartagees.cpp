/* depensespartagees.cpp
 * version 21
 * H. Mathieu Steinbach, univ. Lorraine
 */

#include "depensespartagees.hpp"
#include "ui_depensespartagees.h"

DepensesPartagees::DepensesPartagees(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::DepensesPartagees)
{
    ui->setupUi(this);
}

// Constructeur de la classe DepensesPartagees.
//
// QWidget parent
// Compte le compte
// GestionnaireDialogue gd
DepensesPartagees::DepensesPartagees(QWidget* parent, const std::string compte, const GestionnaireDialogue& gd)
    : QDialog(parent)
    , ui(new Ui::DepensesPartagees)
    , gestionnaire(gd)
    , compte(compte)
{
    ui->setupUi(this);
    ui->nomDuCompte->setText(compte.c_str());
    ui->typeDuCompte->setText("Compte de dépenses partagées");

    std::string liste_membres_concat;
    std::vector<std::string> liste_membres = gestionnaire.getGestionnaireBDD().recuperer_liste_membres(compte);
    for (int i = 0; i < (int)liste_membres.size() - 1; ++i) {
        liste_membres_concat.append(gestionnaire.getGestionnaireBDD().recherche_utilisateur(liste_membres[i].c_str()).get_nom_utilisateur()).append(", ");
    }
    liste_membres_concat.append(gestionnaire.getGestionnaireBDD().recherche_utilisateur(liste_membres[liste_membres.size() - 1].c_str()).get_nom_utilisateur().append("."));

    ui->membresDuCompte->setText(liste_membres_concat.c_str());

    raffraichir_affichage();
}

//Destructeur de la classe DepensesPartagees.
DepensesPartagees::~DepensesPartagees()
{
    delete ui;
}

// La procédure qui raffraichit l'affichage d'un compte commun.
//
// version 20 Hugo Iopeti, univ. Lorraine
void DepensesPartagees::raffraichir_affichage()
{
    std::string liste_transactions_concat;
    std::vector<std::string> liste_transactions = gestionnaire.getGestionnaireBDD().recuperer_liste_transactions(compte);

    int montant_total = 0;
    for (int i = 0; i < (int)liste_transactions.size(); ++i) {
        QStringList liste = QString(liste_transactions[i].c_str()).split(" ");
        int montant = atoi(liste[2].toStdString().c_str());
        std::string utilisateur;
        std::string receveur;
        utilisateur = gestionnaire.getGestionnaireBDD().recherche_utilisateur(liste[0]).get_nom_utilisateur();
        receveur = gestionnaire.getGestionnaireBDD().recherche_utilisateur(liste[1]).get_nom_utilisateur();
        //On gère l'affichage selon si l'utilisateur dépose ou retire de l'argent.
        if (receveur == "") {
            liste_transactions_concat.append("- ").append(utilisateur).append(" a dépensé ").append(std::to_string(montant)).append("€.\n");
        } else {
            liste_transactions_concat.append("- ").append(utilisateur).append(" a donné à ").append(receveur).append(" ").append(std::to_string(montant)).append("€.\n");
        }
        montant_total += montant; //On calcul le solde d'un compte commun.
    }
    ui->Liste->setText(liste_transactions_concat.c_str());
}

// La procédure associée à un clic de bouton retour.
void DepensesPartagees::on_retour_clicked()
{
    this->reject(); // On ferme la fenêtre de dialogue.
}

// La procédure qui gère l'enregistrement d'une transaction après une action sur le bouton correspondant.
void DepensesPartagees::on_enregistrer_clicked()
{
    QString montant = ui->montant->toPlainText(); //On récupère le montant rentré par l'utilisateur.
    QString receveur = ui->receveur->toPlainText();
    QString donneur = ui->donneur->toPlainText();
    time_t now = time(nullptr); //On génère l'id d'un transaction avec le temps actuel en millisecondes.
    gestionnaire.getGestionnaireBDD().ajouter_transaction(now, compte, donneur.toStdString(), receveur.toStdString(), montant.toInt());
    raffraichir_affichage();
}
