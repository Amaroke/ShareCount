/* gestionnairedialogue.cpp
 * version 5
 * H. Iopeti, univ. Lorraine
 */

#include "gestionnairedialogue.hpp"

// Constructeur de la classe GestionnaireDialogue.
GestionnaireDialogue::GestionnaireDialogue()
    : utilisateur_connecte("", "", "")
    , utilisateurs_enregistres()
    , gestionnaire_bdd()
{
}

//Destructeur de la classe GestionnaireDialogue.
GestionnaireDialogue::~GestionnaireDialogue() { }

//Fonction qui retourne un utilisateur connecté.
Utilisateur GestionnaireDialogue::get_utilisateur_connecte()
{
    return utilisateur_connecte;
}

//Fonction qui définit un utilisateur connecté.
void GestionnaireDialogue::set_utilisateur_connecte(const Utilisateur& utilisateur)
{
    utilisateur_connecte = utilisateur;
    //POUR TESTER, TEMPORAIRE
    std::cout
        << "Bienvenue "
        << utilisateur_connecte.get_nom_utilisateur()
        << " vous êtes connecté à ShareCount !\n";
    fflush(stdout);
}

//Fonction qui recherche un utilisateur à l'aide de son mail.
Utilisateur GestionnaireDialogue::recherche_utilisateur(const std::string& adresse_mail)
{
    QString mail = QString(adresse_mail.c_str());
    return gestionnaire_bdd.recherche_utilisateur(mail);
}

// Fonction qui ajoute un utilisateur à la liste des utilisateurs de l'application.
void GestionnaireDialogue::ajouter_utilisateur(const Utilisateur& utilisateur)
{
    if (!gestionnaire_bdd.ajouterUtilisateur(utilisateur))
        qDebug() << "Ajout de l'utilisateur impossible";
}

// Fonction qui crée le bon compte à partir des paramètes
// et l'ajoute à la liste des comptes enregistrés. @version 7 @author L. Yvoz, univ. Lorraine
//
// nom le nom du compte à créer
// type_compte un chiffre représentant le type du compte à créer,
// 1 : dépenses partagées, 2 : cagnotte, 3 : compte commun.
void GestionnaireDialogue::ajouter_compte(const std::string& nom, const int type_compte)
{
    gestionnaire_bdd.ajouter_compte_bdd(utilisateur_connecte.get_adresse_mail(), nom, type_compte);
}

GestionnaireBDD GestionnaireDialogue::getGestionnaireBDD()
{
    return gestionnaire_bdd;
}
