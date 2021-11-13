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
    /// @brief La liste des utilisateurs enregistrés sur l'application. @version 5 @author L. Yvoz, univ. Lorraine
    std::vector<Utilisateur> utilisateurs_enregistres;

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
    void set_utilisateur_connecte(Utilisateur utilisateur);
    /// @brief Fonction qui trouve un utilisateur à l'aide de son mail.
    ///
    /// @return Un utilisteur qui correspond à l'email donné.
    Utilisateur recherche_utilisateur(std::string adresse_mail);
    /// @brief Fonction qui ajoute un utilisateur à la liste des utilisateurs de l'application. @version 5 @author L. Yvoz, univ. Lorraine
    ///
    /// @param utilisateur l'utilisateur à ajouter
    void ajouter_utilisateur(Utilisateur utilisateur);
};

#endif // GESTIONNAIREDIALOGUE_HPP
