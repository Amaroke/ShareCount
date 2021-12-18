/** @file compte.hpp
 **
 ** @brief Le fichier qui contient la classe Compte.
 **
 ** @version 7
 **
 ** @author L. Yvoz, univ. Lorraine
 **/

#ifndef COMPTE_HPP
#define COMPTE_HPP

#include "utilisateur.hpp"
#include <vector>

/**
 ** @brief La classe Compte
 **
 ** Elle contient les attributs nécessaires à un compte et
 ** définit les méthodes abstraites des comptes.
 **
 ** @version 7
 **
 ** @author L. Yvoz, univ. de Lorraine
 */

class Compte {
private:
    /// @brief L'utilisateur qui a créé le compte.
    Utilisateur createur;

    /// @brief Le nom du compte.
    std::string nom;

    /// @brief le type du compte @version 17 @author L. Yvoz, univ. lorraine
    int type;

public:
    /// @brief Le constructeur permet de définir les champs
    ///        de la classe en fonction des paramètres passés.
    ///
    /// @param createur l'utilisateur ayant créé le compte.
    /// @param nom le nom du compte.
    /// @param type le type du compte représenté par un entier (1 : compte de dépenses partagées, 2 : cagnotte, 3 : compte commun).
    /// @version 17 @author L. Yvoz, univ. lorraine
    Compte(const Utilisateur& createur, const std::string& nom, const int type);

    /// @brief Le destructeur ne fait rien.
    ~Compte();

    /// @brief Fonction qui retourne un entier correspondant au type du compte
    ///
    /// @return le type du compte
    /// @version 17 @author L. Yvoz, univ. lorraine
    int getType();
};

#endif // COMPTE_HPP
