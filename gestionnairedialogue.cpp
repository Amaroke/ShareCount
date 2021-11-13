/* gestionnairedialogue.cpp
 * version 5
 * H. Iopeti, univ. Lorraine
 */

#include "gestionnairedialogue.hpp"

// Constructeur de la classe GestionnaireDialogue.
GestionnaireDialogue::GestionnaireDialogue()
    : utilisateur_connecte("", 0, "", "")
{

    // POUR TEST
    set_utilisateur_connecte(Utilisateur("a", 1, "aa", "aaa"));
}

//Destructeur de la classe GestionnaireDialogue.
GestionnaireDialogue::~GestionnaireDialogue() { }

//Fonction qui retourne un utilisateur connecté.
Utilisateur GestionnaireDialogue::get_utilisateur_connecte()
{
    return utilisateur_connecte;
}

//Fonction qui défini un utilisateur connecté.
void GestionnaireDialogue::set_utilisateur_connecte(Utilisateur utilisateur)
{
    utilisateur_connecte = utilisateur;
}

//Fonction qui recherche un utilisateur à l'aide de son mail et de son mot de passe.
Utilisateur GestionnaireDialogue::recherche_utilisateur(std::string adresse_mail,
                                                        std::string mot_de_passe)
{
    return Utilisateur("", -1, adresse_mail, mot_de_passe);
}
