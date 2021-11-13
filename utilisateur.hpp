/** @file utilisateur.hpp
 **
 ** @brief Le fichier contenant la description de la classe Utilisateur.
 **
 ** @version 3
 **
 ** @author L. Yvoz, univ. de Lorraine
 **/
#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>

/** @brief La classe Utilisateur est la classe représentant les données d'un
 *utilisateur.
 **
 ** Elle contient 4 attributs, 1 méthode de construction, 1 méthode de
 *destruction
 ** et 8 méthodes d'obtention et de modification des attributs cités
 *précédemment.
 **
 ** @version 3
 **
 ** @author L. Yvoz, univ. de Lorraine
 **/
class Utilisateur {
private:
    /// @brief Le nom d'utilisateur.
    std::string nom_utilisateur;
    /// @brief L'adresse mail de l'utilisateur.
    std::string adresse_mail;
    /// @brief Le mot de passe de l'utilisateur.
    std::string mot_de_passe;

public:
    /// @brief Le constructeur, assigne les valeurs entrées en paramètre aux
    /// attributs de la classe.
    ///
    /// @param nom_utilisateur le nom d'utilisateur
    /// @param id l'identifiant de l'utilisateur
    /// @param adresse_mail l'adresse mail
    /// @param mot_de_passe le mot de passe
    Utilisateur(std::string nom_utilisateur,
                std::string adresse_mail,
                std::string mot_de_passe);
    /// @brief Le destructeur, ne fait rien.
    ~Utilisateur();
    /// @brief Méthode d'obtention de l'attribut nom_utilisateur.
    ///
    /// @return La chaine de caractères demandée.
    std::string get_nom_utilisateur();
    /// @brief Méthode de modification de l'attribut nom_utilisateur.
    ///
    /// @param La chaine de caractères à utiliser pour la modification.
    void set_nom_utilisateur(std::string nom_utilisateur);
    /// @brief Méthode d'obtention de l'attribut adresse_mail.
    ///
    /// @return La chaine de caractères demandée.
    std::string get_adresse_mail();
    /// @brief Méthode de modification de l'attribut adresse_mail.
    ///
    /// @param La chaine de caractères à utiliser pour la modification.
    void set_adresse_mail(std::string adresse_mail);
    /// @brief Méthode d'obtention de l'attribut mot_de_passe.
    ///
    /// @return La chaine de caractères demandée.
    std::string get_mot_de_passe();
    /// @brief Méthode de modification de l'attribut mot_de_passe.
    ///
    /// @param La chaine de caractères à utiliser pour la modification.
    void set_mot_de_passe(std::string adresse_mail);
};

#endif // UTILISATEUR_H
