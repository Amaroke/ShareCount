/* utilisateur.cpp
 *
 * Le fichier contenant la classe Utilisateur.
 *
 * L. Yvoz, univ. de Lorraine
 */

#include "utilisateur.hpp"
// Le constructeur, assigne les valeurs entrées en paramètre aux attributs de la classe.
//
// nom_utilisateur le nom d'utilisateur
// id l'identifiant de l'utilisateur
// adresse_mail l'adresse mail
// mot_de_passe le mot de passe
Utilisateur::Utilisateur(std::string nom_utilisateur, int id, std::string adresse_mail, std::string mot_de_passe) :
    nom_utilisateur(nom_utilisateur),
    id(id),
    adresse_mail(adresse_mail),
    mot_de_passe(mot_de_passe)
{

}
// Le destructeur, ne fait rien.
Utilisateur::~Utilisateur()
{
}
// Méthode d'obtention de l'attribut nom_utilisateur.
//
// La chaine de caractères demandée.
std::string Utilisateur::get_nom_utilisateur()
{
    return nom_utilisateur;
}
// Méthode de modification de l'attribut nom_utilisateur.
//
// La chaine de caractères à utiliser pour la modification.
void Utilisateur::set_nom_utilisateur(std::string nom_utilisateur)
{
   Utilisateur::nom_utilisateur = nom_utilisateur;
}
// Méthode d'obtention de l'attribut id.
//
// L'entier demandé.
int Utilisateur::get_id()
{
    return id;
}
// Méthode de modification de l'attribut id.
//
// La chaine de caractères l'entier à utiliser pour la modification.
void Utilisateur::set_id(int id)
{
    Utilisateur::id = id;
}
// Méthode d'obtention de l'attribut adresse_mail.
//
// La chaine de caractères demandée.
std::string Utilisateur::get_adresse_mail()
{
    return adresse_mail;
}
// Méthode de modification de l'attribut adresse_mail.
//
// La chaine de caractères à utiliser pour la modification.
void Utilisateur::set_adresse_mail(std::string adresse_mail)
{
    Utilisateur::adresse_mail = adresse_mail;
}
// Méthode d'obtention de l'attribut mot_de_passe.
//
// La chaine de caractères demandée.
std::string Utilisateur::get_mot_de_passe()
{
    return mot_de_passe;
}
// Méthode de modification de l'attribut mot_de_passe.
//
// La chaine de caractères à utiliser pour la modification.
void Utilisateur::set_mot_de_passe(std::string mot_de_passe)
{
    Utilisateur::mot_de_passe = mot_de_passe;
}
