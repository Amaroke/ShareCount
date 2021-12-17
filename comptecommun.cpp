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
    std::vector<std::string> liste_membres;
    for(std::string s : liste_membres){
        liste_membres_concat.append(s).append(" ");
    }
    ui->membresDuCompte->setText(liste_membres_concat.c_str());

    ui->soldeDuCompte->setText("Promos");

    std::string liste_transactions_concat;
    std::vector<std::string> liste_transactions;
    for(std::string s : liste_transactions){
        liste_transactions_concat.append(s).append(" ");
    }
    ui->Liste->setText(liste_transactions_concat.c_str());
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
void CompteCommun::on_retirerDeLArgent_clicked()
{
    QString montant = ui->Montant->toPlainText();
}

// La procédure associée à un clic de dépot d'argent.
void CompteCommun::on_deposerDeLArgent_clicked()
{
    QString montant = ui->Montant->toPlainText();
}

