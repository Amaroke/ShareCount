/* compte.cpp
 * version 7
 * L. Yvoz, univ. Lorraine
 */
#include "compte.hpp"

// Le constructeur permet de définir les champs
//        de la classe en fonction des paramètres passés.
//
// Ce constructeur est protégé car la classe Compte est abstraite :
// seules ses classes filles peuvent être instanciées
//
//  createur l'utilisateur ayant créé le compte.
//  nom le nom du compte.
Compte::Compte(Utilisateur createur, std::string nom) :
  createur(createur),
  participants(),
  nom(nom)
{
}

// Le destructeur ne fait rien.
Compte::~Compte() {}

// Procédure permettant d'ajouter un utilisateur à la liste des participants du compte.
//
// utilisateur l'utilisateur à rajouter
void Compte::ajouterUtilisateur(Utilisateur utilisateur) {
    participants.push_back(utilisateur);
}

// Le constructeur appelle celui de Compte avec les paramètres donnés.
//
// createur l'utilisateur ayant créé le compte.
// nom le nom du compte.
CompteDepensesPartagees::CompteDepensesPartagees(Utilisateur createur, std::string nom):
    Compte(createur, nom)
{
}

// Le destructeur appelle celui de Compte.
CompteDepensesPartagees::~CompteDepensesPartagees()
{
}

// Le constructeur appelle celui de Compte avec les paramètres donnés.
//
//  createur l'utilisateur ayant créé le compte.
//  nom le nom du compte.
Cagnotte::Cagnotte(Utilisateur createur, std::string nom):
    Compte(createur, nom)
{
}

// Le destructeur ne fait rien
Cagnotte::~Cagnotte()
{
}

// Le constructeur appelle celui de Compte avec les paramètres donnés.
//
//  createur l'utilisateur ayant créé le compte.
//  nom le nom du compte.
CompteCommun::CompteCommun(Utilisateur createur, std::string nom):
    Compte(createur, nom)
{
}

// Le destructeur ne fait rien.
CompteCommun::~CompteCommun()
{
}
