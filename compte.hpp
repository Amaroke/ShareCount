/** @file compte.hpp
 **
 ** @brief Le fichier qui contient la classe abstraite Compte et ses classes filles
 ** CompteDepensesPartagees, Cagnotte et CompteCommun.
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
 ** @brief La classe abstraite Compte
 **
 ** Elle contient les attributs nécessaires à un compte et
 ** définit les méthodes abstraites des comptes.
 **
 ** @version 7
 **
 ** @author L. Yvoz, univ. de Lorraine
 */
class Compte
{
private:

protected:
    /// @brief L'utilisateur qui a créé le compte.
    Utilisateur createur;

    /// @brief Les utilisateurs ayant accés au compte.
    std::vector<Utilisateur> participants;

    /// @brief Le nom du compte.
    std::string nom;

    /// @brief Le constructeur permet de définir les champs
    ///        de la classe en fonction des paramètres passés.
    ///
    /// Ce constructeur est protégé car la classe Compte est abstraite :
    /// seules ses classes filles peuvent être instanciées
    ///
    /// @param  createur l'utilisateur ayant créé le compte.
    /// @param  nom le nom du compte.
    Compte(Utilisateur createur, std::string nom);

public:
    /// @brief Le destructeur ne fait rien.
    ~Compte();
    /// @brief Procédure permettant d'ajouter un utilisateur à la liste des participants du compte.
    ///
    /// @param utilisateur l'utilisateur à rajouter
    virtual void ajouterUtilisateur(Utilisateur utilisateur);
};


// === Classe concrète : compte de dépenses partagées =================================

/** @brief La classe CompteDepensesPartagees est un compte qui ne permet pas
 ** d'échange d'argent direct, seul l'écriture d'informations et possible.
 **
 ** Elle appelle les constructeurs et destructeur de Compte,
 ** définit les méthodes et attributs supplémentaires nécessaires.
 **
 ** @author L. Yvoz, univ. de Lorraine
 **/
class CompteDepensesPartagees : public Compte
{
private:

protected:

public:
    /// @brief Le constructeur appelle celui de Compte avec les paramètres donnés.
    ///
    /// @param  createur l'utilisateur ayant créé le compte.
    /// @param  nom le nom du compte.
    CompteDepensesPartagees(Utilisateur createur, std::string nom);

    /// @brief Le destructeur ne fait rien.
    ~CompteDepensesPartagees();
};

// === Classe concrète : cagnotte =================================

/** @brief La classe Cagnotte est un compte qui permet des dépots d'argent par tous
 ** ces participants mais le retrait n'est possible que pour le participant le plus haut placé.
 **
 ** Elle appelle les constructeurs et destructeur de Compte,
 ** définit les méthodes et attributs supplémentaires nécessaires.
 **
 ** @author L. Yvoz, univ. de Lorraine
 **/
class Cagnotte : public Compte
{
private:

protected:

public:
    /// @brief Le constructeur appelle celui de Compte avec les paramètres donnés.
    ///
    /// @param  createur l'utilisateur ayant créé le compte.
    /// @param  nom le nom du compte.
    Cagnotte(Utilisateur createur, std::string nom);

    /// @brief Le destructeur ne fait rien
    ~Cagnotte();
};

// === Classe concrète : compte commun =================================

/** @brief La classe Cagnotte est un compte qui permet des dépots et retraits
 ** d'argent par tous ces participants, les retraits nécessitent des confirmation.
 **
 ** Elle appelle les constructeurs et destructeur de Compte,
 ** définit les méthodes et attributs supplémentaires nécessaires.
 **
 ** @author L. Yvoz, univ. de Lorraine
 **/
class CompteCommun : public Compte
{
private:

public:
    /// @brief Le constructeur appelle celui de Compte avec les paramètres donnés.
    ///
    /// @param  createur l'utilisateur ayant créé le compte.
    /// @param  nom le nom du compte.
    CompteCommun(Utilisateur createur, std::string nom);

    /// @brief Le destructeur ne fait rien.
    ~CompteCommun();
};
#endif // COMPTE_HPP
