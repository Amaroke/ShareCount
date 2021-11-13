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
    Utilisateur utilisateur_connecte;

public:
    GestionnaireDialogue();
    /// @brief Destructeur de la classe, ne fait rien.
    ~GestionnaireDialogue();
    /// @brief Fonction qui retourne l'utilisateur connecté.
    Utilisateur get_utilisateur_connecte();
    /// @brief Fonction qui définit un utilisateur connecté.
    void set_utilisateur_connecte(Utilisateur utilisateur);
    /// @brief Fonction qui trouve un utilisateur à l'aide de son mail et de son mot de passe.
    Utilisateur recherche_utilisateur(std::string adresse_mail,
                                      std::string mot_de_passe);
};

#endif // GESTIONNAIREDIALOGUE_HPP
