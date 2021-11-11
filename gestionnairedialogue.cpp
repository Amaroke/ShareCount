#include "gestionnairedialogue.hpp"

GestionnaireDialogue::GestionnaireDialogue()
    : utilisateur_connecte("", 0, "", "")
{

    // POUR TEST
    set_utilisateur_connecte(Utilisateur("a", 1, "aa", "aaa"));
}

GestionnaireDialogue::~GestionnaireDialogue() { }

Utilisateur GestionnaireDialogue::get_utilisateur_connecte()
{
    return utilisateur_connecte;
}

void GestionnaireDialogue::set_utilisateur_connecte(Utilisateur utilisateur)
{
    utilisateur_connecte = utilisateur;
}

Utilisateur GestionnaireDialogue::recherche_utilisateur(std::string adresse_mail,
                                                        std::string mot_de_passe)
{
    return Utilisateur("", -1, adresse_mail, mot_de_passe);
}
