/* utilisateur.cpp
 * Le fichier contenant la classe Utilisateur.
 * L. Yvoz, univ. de Lorraine
 */

#include "utilisateur.hpp"
// Le constructeur, assigne les valeurs entrées en paramètre aux attributs de la
// classe.
//
// nom_utilisateur le nom d'utilisateur
// adresse_mail l'adresse mail
// mot_de_passe le mot de passe
Utilisateur::Utilisateur(const std::string& adresse_mail,
    const std::string& mot_de_passe,
    const std::string& nom_utilisateur)
    : nom_utilisateur(nom_utilisateur)
    , adresse_mail(adresse_mail)
    , mot_de_passe(mot_de_passe)
{
}
// Le destructeur, ne fait rien.
Utilisateur::~Utilisateur() { }
// Méthode d'obtention de l'attribut nom_utilisateur.
//
// La chaine de caractères demandée.
std::string Utilisateur::get_nom_utilisateur() { return nom_utilisateur; }
// Méthode de modification de l'attribut nom_utilisateur.
//
// La chaine de caractères à utiliser pour la modification.
void Utilisateur::set_nom_utilisateur(const std::string& nom_utilisateur)
{
    Utilisateur::nom_utilisateur = nom_utilisateur;
}
// Méthode d'obtention de l'attribut adresse_mail.
//
// La chaine de caractères demandée.
std::string Utilisateur::get_adresse_mail() { return adresse_mail; }
// Méthode de modification de l'attribut adresse_mail.
//
// La chaine de caractères à utiliser pour la modification.
void Utilisateur::set_adresse_mail(const std::string& adresse_mail)
{
    Utilisateur::adresse_mail = adresse_mail;
}
// Méthode d'obtention de l'attribut mot_de_passe.
//
// La chaine de caractères demandée.
std::string Utilisateur::get_mot_de_passe() { return mot_de_passe; }
// Méthode de modification de l'attribut mot_de_passe.
//
// La chaine de caractères à utiliser pour la modification.
void Utilisateur::set_mot_de_passe(const std::string& mot_de_passe)
{
    Utilisateur::mot_de_passe = mot_de_passe;
}
