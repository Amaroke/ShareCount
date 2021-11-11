#include "gestionnairedialogue.hpp"

GestionnaireDialogue::GestionnaireDialogue() :
    utilisateur_connecte("",0,"","")
{   
}

Utilisateur GestionnaireDialogue::get_utilisateur_connecte(){
    return utilisateur_connecte;
}

void GestionnaireDialogue::set_utilisateur_connecte(Utilisateur utilisateur){
    utilisateur_connecte = utilisateur;
}
