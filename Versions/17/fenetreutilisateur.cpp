/* fenetreutilisateur.cpp
 * version 10
 * H. Mathieu Steinbach, univ. Lorraine
 */

#include "fenetreutilisateur.hpp"
#include "ui_fenetreutilisateur.h"

FenetreUtilisateur::FenetreUtilisateur(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::FenetreUtilisateur)
{
    ui->setupUi(this);
    afficher_comptes();
}

FenetreUtilisateur::FenetreUtilisateur(QWidget* parent, const GestionnaireDialogue& gd)
    : QMainWindow(parent)
    , ui(new Ui::FenetreUtilisateur)
    , gestionnaire_dialogue(gd)
{
    ui->setupUi(this);
    afficher_comptes();
}

FenetreUtilisateur::~FenetreUtilisateur()
{
    delete ui;
}

void FenetreUtilisateur::fenetre_creer_un_compte_argent()
{
    CreerCompte* creercompte;
    creercompte = new CreerCompte;
    creercompte->setWindowTitle("Se connecter"); // On nomme la fenêtre.
    creercompte->exec(); // On affiche la fenêtre de dialogue, tant qu'elle n'est pas fermée, on attends.
    if (creercompte->result() == QDialog::Accepted) {
        std::string nom;
        int choix;
        creercompte->getDonnees(nom, choix);
        if (choix != 4) {
            gestionnaire_dialogue.ajouter_compte(nom, choix);
            std::cout << " " << nom << choix;
            fflush(stdout);
        } else {
        }
    }
}

void FenetreUtilisateur::on_creerCompte_clicked()
{
    fenetre_creer_un_compte_argent();
    afficher_comptes();
}

// Procédure qui déconnecte l'utilisateur
//
// version 14 Hugo Iopeti, univ. Lorraine
void FenetreUtilisateur::fenetre_creer_un_accueil()
{
    //On créer une fenêtre de l'accueil.
    gestionnaire_dialogue.getGestionnaireBDD().fermeturebdd();
    Accueil* accueil;
    accueil = new Accueil();
    accueil->setWindowTitle("Accueil"); // On nomme la fenêtre.
    accueil->show(); // On affiche la fenêtre de dialogue, tant qu'elle n'est pas fermée, on attends.
    //On ferme la fenêtre actuelle
    this->close();
}

// Procédure qui déconnecte l'utilisateur
//
// version 14 Hugo Iopeti, univ. Lorraine
void FenetreUtilisateur::on_seDeconnecter_clicked()
{
    fenetre_creer_un_accueil();
}

// La fonction qui affiche les comptes dans une liste déroulante. @version 15 @author H. Mathieu Steinbach, univ. Lorraine
void FenetreUtilisateur::afficher_comptes()
{
    ui->comboBox->clear();
    ui->comboBox->addItem("");
    std::vector<std::string> liste_comptes = gestionnaire_dialogue.getGestionnaireBDD().recuperer_compte_utilisateur(gestionnaire_dialogue.get_utilisateur_connecte().get_adresse_mail().c_str());
    for (int i = 0; i < (int)liste_comptes.size(); ++i) {
        ui->comboBox->addItem(liste_comptes[i].c_str());
    }
}

void FenetreUtilisateur::on_supprimer_compte_clicked()
{
    gestionnaire_dialogue.getGestionnaireBDD().supprimer_compte(ui->comboBox->currentText(), gestionnaire_dialogue.get_utilisateur_connecte().get_adresse_mail().c_str());
    afficher_comptes();
}

void FenetreUtilisateur::on_afficherinfo_clicked()
{
    //On récupère le compte actuellement sélectionné
    Compte compte = gestionnaire_dialogue.getGestionnaireBDD().recherche_compte(ui->comboBox->currentText().toStdString().c_str());

    //Selon le type du compte, on affiche une fenêtre différente
    switch (compte.getType()) {
    case 1:
        //AFFICHAGE DE LA FENETRE CORRESPONDANT AU COMPTE DE DEPENSES PARTAGEES
        break;
    case 2:
        //AFFICHAGE DE LA FENETRE CORRESPONDANT A LA CAGNOTTE
        break;
    case 3:
        //AFFICHAGE DE LA FENETRE CORRESPONDANT AU COMPTE COMMUN
        break;
    default:
        qDebug() << "Impossible d'afficher les données du compte";
    }
}

void FenetreUtilisateur::on_invitercompte_clicked()
{
    Invitation* invitation;
    invitation = new Invitation(this, ui->comboBox->currentText().toStdString(), gestionnaire_dialogue);
    invitation->setWindowTitle("Invitation"); // On nomme la fenêtre.
    invitation->show(); // On affiche la fenêtre de dialogue, tant qu'elle n'est pas fermée, on attends.
}
