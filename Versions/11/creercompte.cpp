/* creercompte.cpp
 * version 10
 * H. Mathieu Steinbach, univ. Lorraine
 */

#include "creercompte.hpp"
#include "ui_creercompte.h"

// Constructeur de la classe par défaut.
CreerCompte::CreerCompte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreerCompte)
{
    ui->setupUi(this);
}

// Destructeur de la classe.
CreerCompte::~CreerCompte()
{
    delete ui;
}

// Fonction permettant de récupérer les informations rentrée par l'utilisateur.
//
// adresse_mail un pointeur contenant l'adresse vers le string du nom donné
// choix un pointeur contenant l'adresse vers le choix de type de compte
void CreerCompte::getDonnees(std::string& nom, int& choix)
{
    nom = ui->saisie_nom->toPlainText().toStdString();
      // 1 : dépenses partagées, 2 : cagnotte, 3 : compte commun, 4 : problème
    choix = ui->depens_part->isChecked() ? 1 : ui->cagnotte->isChecked() ? 2 : ui->compte_co->isChecked() ? 3 : 4;
    if (choix == 4) {
        perror("Erreur de selection de type de compte");
        exit(EXIT_FAILURE);
    }
}

// La fonction associée à un clic de bouton Annuler.
void CreerCompte::on_annuler_clicked()
{
    this->reject();
}

// La fonction associée à un clic de bouton Valider.
void CreerCompte::on_valider_clicked()
{
    this->accept();
}

