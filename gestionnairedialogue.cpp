/* gestionnairedialogue.cpp
 * version 5
 * H. Iopeti, univ. Lorraine
 */

#include "gestionnairedialogue.hpp"

// Constructeur de la classe GestionnaireDialogue.
GestionnaireDialogue::GestionnaireDialogue()
    : utilisateur_connecte("", "", "")
    , utilisateurs_enregistres()
{
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
    std::cout
        << "Bienvenue "
        << utilisateur_connecte.get_nom_utilisateur()
        << " vous êtes connecté à ShareCount !\n";
    fflush(stdout);
}

//Fonction qui recherche un utilisateur à l'aide de son mail.
Utilisateur GestionnaireDialogue::recherche_utilisateur(std::string adresse_mail)
{
    Utilisateur utilisateur = Utilisateur("", "", "");
    int taille = utilisateurs_enregistres.size();
    for (int i = 0; i < taille; i++) {
        if (utilisateurs_enregistres[i].get_adresse_mail() == adresse_mail) {
            utilisateur = utilisateurs_enregistres[i];
        }
    }
    return utilisateur;
}

// Fonction qui ajoute un utilisateur à la liste des utilisateurs de l'application.
void GestionnaireDialogue::ajouter_utilisateur(Utilisateur utilisateur)
{
    utilisateurs_enregistres.push_back(utilisateur);
}
