/* compte.cpp
 * version 7
 * L. Yvoz, univ. Lorraine
 */

#include "compte.hpp"

// Le constructeur permet de définir les champs
// de la classe en fonction des paramètres passés.
//
// createur l'utilisateur ayant créé le compte.
// nom le nom du compte.
// type le type du compte représenté par un entier (1 : compte de dépenses partagées, 2 : cagnotte, 3 : compte commun).
Compte::Compte(const Utilisateur& createur, const std::string& nom, const int type)
    : createur(createur)
    , nom(nom)
    , type(type)
{
}

// Le destructeur ne fait rien.
Compte::~Compte() { }

// Fonction qui retourne un entier correspondant au type du compte
//
// le type du compte
// version 17, L. Yvoz, univ. lorraine
int Compte::getType()
{
    return type;
}
