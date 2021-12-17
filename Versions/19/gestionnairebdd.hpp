/** @file gestionnairebdd.hpp
 **
 ** @brief Le fichier qui contient la classe GestionnaireBDD.
 **
 ** @version 11
 **
 ** @author H. Iopeti, univ. Lorraine
 **/

#ifndef GESTIONNAIREBDD_HPP
#define GESTIONNAIREBDD_HPP

#include "compte.hpp"
#include "utilisateur.hpp"
#include <QFileDialog>
#include <QTableView>
#include <QtSql>
#include <iostream>

class GestionnaireBDD {
private:
public:
    /// @brief  Constructeur de la classe.
    GestionnaireBDD();
    /// @brief Fonction qui ajoute un utilisateur à la base de données
    ///
    /// @param utilisateur l'utilisateur à ajouter
    ///
    /// @return un booleen valant faux si l'ajout ne s'est pas bien passé
    bool ajouterUtilisateur(Utilisateur utilisateur);
    /// @brief Fonction qui recherche un utilisateur dans la base de données à partir d'un email
    ///
    /// @param mail l'adresse mail à partir de laquelle la recherche s'effectue
    ///
    /// @return l'utilisateur trouvé ou un utilisateur avec des données vides si aucun utilisateur n'a été trouvé
    Utilisateur recherche_utilisateur(const QString& mail);
    /// @brief Fonction qui ajoute un compte à la base de données
    ///
    /// @param compte le compte à ajouter
    ///
    /// @version 13 @author H. Mathieu Steinbach, univ. Lorraine
    void ajouter_compte_bdd(const std::string email, const std::string nom_compte, int type);
    /// @brief Fonction qui recherche un compte dans la base de données à partir d'un nom de compte
    ///
    /// @param compte le nom à partir duquel la recherche s'effectue
    ///
    /// @return le compte trouvé ou un compte avec des données vides si aucun compte n'a été trouvé
    /// @version 17 @author L. Yvoz, univ. Lorraine
    Compte recherche_compte(const QString& compte);
    /// @brief Fonction qui retourne la liste des comtpes lié à un utilisateur
    ///
    /// @param mail l'adresse mail à partir de laquelle la recherche s'effectue
    ///
    /// @return la liste des noms des comptes
    ///
    /// @version 15 @author H. Mathieu Steinbach, univ. Lorraine
    std::vector<std::string> recuperer_compte_utilisateur(const std::string mail);
    /// @brief Procédure qui ajoute une transaction à la base de données
    ///
    /// @param id l'identifiant de la transaction
    /// @param nom_compte le nom du comte sur lequel se déroule la la transaction
    /// @param donneur l'addresse mail de l'utilisateur initiant la transaction
    /// @param receveur l'addresse mail de l'utilisateur initiant la transaction
    /// @param montant le montant de la transaction
    void ajouter_transaction(const int id, const std::string nom_compte, const std::string donneur, const std::string receveur, const int montant);
    /// @brief Procédure qui supprimer un compte de la base de données
    ///
    /// @param nom le nom du compte à supprimer
    ///
    /// @version 16 @author H. Mathieu Steinbach, univ. Lorraine
    void supprimer_compte(const QString nom, const QString utilisateur_connecte);
    /// @brief Procédure qui ajoute un utilisateur à un compte de la base de données
    ///
    /// @param nom le nom du compte concerné
    /// @param l'email de l'utilisateur a ajouter
    ///
    /// @version 16 @author H. Mathieu Steinbach, univ. Lorraine
    void ajouter_utilisateur_compte(const std::string compte, const std::string mail);
    /// @brief Procédure qui ferme la connection à la base de données
    void fermeturebdd();
    /// @brief Fonction qui récupère la liste des membres d'un compte.
    ///
    /// @param compte le compte de l'utilisateur concerné
    ///
    /// @version 19 @author H. Iopeti, univ. Lorraine
    std::vector<std::string> recuperer_liste_membres(const std::string compte);
    /// @brief Fonction qui récupère la liste des transactions d'un compte.
    ///
    /// @param compte le compte de l'utilisateur concerné
    ///
    /// @version 19 @author H. Iopeti, univ. Lorraine
    std::vector<std::string> recuperer_liste_transactions(const std::string compte);
};

#endif // GESTIONNAIREBDD_HPP
