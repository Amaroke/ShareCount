/** @file fenetreUtilisateur.hpp
 **
 ** @brief Le fichier qui contient la classe FenetreUtilisateur.
 **
 ** @version 9
 **
 ** @author H. Mathieu Steinbach, univ. Lorraine
 **/

#ifndef FENETREUTILISATEUR_HPP
#define FENETREUTILISATEUR_HPP

#include "accueil.hpp"
#include "cagnotte.hpp"
#include "comptecommun.hpp"
#include "creercompte.hpp"
#include "depensespartagees.hpp"
#include "gestionnairedialogue.hpp"
#include "invitation.hpp"
#include <QMainWindow>

namespace Ui {
class FenetreUtilisateur;
}

/** @brief La classe FenetreUtilisateur gère l'UI de la fenêtre d'un utilisateur
 **
 ** Elle contient 1 méthode de construction, 1 méthode de destruction
 ** et 2 fonctions.
 **
 ** @version 10
 **
 ** @author H. Mathieu Steinbach, univ. Lorraine
 **/

class FenetreUtilisateur : public QMainWindow {
    Q_OBJECT

public:
    /// @brief Constructeur de la classe par défaut.
    explicit FenetreUtilisateur(QWidget* parent = nullptr);
    /// @brief Destructeur de la classe, ne fait rien.
    ~FenetreUtilisateur();
    /// @brief Constructeur de la classe FenetreUtilisateur.
    /// @param parent Le parent graphique
    /// @param gd Le GestionnaireDialogue de l'application.
    FenetreUtilisateur(QWidget* parent, const GestionnaireDialogue& gd);
    /// @brief Création d'une fenêtre de création de compte @version 10 @author H. Mathieu Steinbach, univ. Lorraine
    void fenetre_creer_un_compte_argent();
    /// @brief Création d'une fenêtre d'accueil @version 14 @author H. Iopeti, univ. Lorraine
    void fenetre_creer_un_accueil();
    /// @brief La fonction qui affiche les comptes dans une liste déroulante. @version 15 @author H. Mathieu Steinbach, univ. Lorraine
    void afficher_comptes();

private slots:
    /// @brief La fonction associée à un clic de bouton de création de compte.
    void on_creerCompte_clicked();
    /// @brief La fonction associée à un clic de bouton de deconnexion.
    void on_seDeconnecter_clicked();
    /// @brief La fonction associée à un clic de bouton de supprimer compte.
    void on_supprimer_compte_clicked();
    /// @brief La fonction associée à un clic de bouton afficher informations.
    void on_afficherinfo_clicked();
    /// @brief La fonction associée à un clic de bouton inviter compte.
    void on_invitercompte_clicked();

private:
    Ui::FenetreUtilisateur* ui;
    /// @brief Le gestionnaire de dialogue de l'application.
    GestionnaireDialogue gestionnaire_dialogue;
};

#endif // FENETREUTILISATEUR_HPP
