/** @file gestionnairedialogue.hpp
 **
 ** @brief Le fichier qui contient la classe GestionnaireDialogue.
 **
 ** @version 5
 **
 ** @author H. Iopeti, univ. Lorraine
 **/

#ifndef GESTIONNAIREDIALOGUE_HPP
#define GESTIONNAIREDIALOGUE_HPP
#include "compte.hpp"
#include "gestionnairebdd.hpp"
#include "utilisateur.hpp"
#include <iostream>
#include <vector>

/** @brief La classe GestionnaireDialogue gère les fenêtres d'alertes.
 **
 ** Elle contient 1 méthode de construction, 1 méthode de destruction
 ** et 3 fonctions.
 **
 ** @version 5
 **
 ** @author H. Iopeti, univ. Lorraine
 **/
class GestionnaireDialogue {
private:
    /// @brief L'utilisateur qui est connecté.
    Utilisateur utilisateur_connecte;
    //TEMPORAIRE, REMPLACE LA BDD :
    /// @brief La liste des utilisateurs enregistrés sur l'application.
    /// @version 5 @author L. Yvoz, univ. Lorraine
    std::vector<Utilisateur> utilisateurs_enregistres;
    /// @brief La liste des comptes enregistrés sur l'application.
    /// @version 7 @author L. Yvoz, univ. Lorraine
    std::vector<Compte> comptes_enregistres;
    /// @brief Le gestionnairebdd de l'application
    /// @version 11 @author H. Mathieu Steinbach, univ. Lorraine
    GestionnaireBDD gestionnaire_bdd;

public:
    /// @brief Constructeur de la classe.
    GestionnaireDialogue();
    /// @brief Destructeur de la classe, ne fait rien.
    ~GestionnaireDialogue();
    /// @brief Fonction qui retourne l'utilisateur connecté.
    ///
    /// @return L'utilisateur qui est connecté.
    Utilisateur get_utilisateur_connecte();
    /// @brief Fonction qui définit un utilisateur connecté.
    ///
    /// @param utilisateur l'utilisateur à connecter
    void set_utilisateur_connecte(const Utilisateur& utilisateur);
    /// @brief Fonction qui trouve un utilisateur à l'aide de son mail.
    ///
    /// @param adresse_mail L'adresse mail de l'utilisateur recherché
    ///
    /// @return Un utilisateur qui correspond à l'email donné.
    Utilisateur recherche_utilisateur(const std::string& adresse_mail);
    /// @brief Fonction qui ajoute un utilisateur à la liste des utilisateurs
    /// de l'application. @version 5 @author L. Yvoz, univ. Lorraine
    ///
    /// @param utilisateur l'utilisateur à ajouter
    void ajouter_utilisateur(const Utilisateur& utilisateur);
    /// @brief Fonction qui crée le bon compte à partir des paramètes
    /// et l'ajoute à la liste des comptes enregistrés. @version 7 @author L. Yvoz, univ. Lorraine
    ///
    /// @param nom le nom du compte à créer
    /// @param type_compte un chiffre représentant le type du compte à créer,
    /// 1 : dépenses partagées, 2 : cagnotte, 3 : compte commun.
    void ajouter_compte(const std::string& nom, const int type_compte);
    /// @brief Fonction qui retourne le gestionnaire de la bdd
    ///
    /// @return le gestionnaire de la bdd
    GestionnaireBDD getGestionnaireBDD();
};

#endif // GESTIONNAIREDIALOGUE_HPP
