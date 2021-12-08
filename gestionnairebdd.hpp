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
    /// @brief Fonction qui recherhce un utilisateur dans la base de données à partir d'un email
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
    /// @brief Procédure qui ajoute une transaction à la base de données
    ///
    /// @param id l'identifiant de la transaction
    /// @param nom_compte le nom du comte sur lequel se déroule la la transaction
    /// @param donneur l'addresse mail de l'utilisateur initiant la transaction
    /// @param receveur l'addresse mail de l'utilisateur initiant la transaction
    /// @param montant le montant de la transaction
    void ajouter_transaction(const int id, const std::string nom_compte, const std::string donneur, const std::string receveur, const int montant);
    /// @brief Procédure qui ferme la connection à la base de données
    void fermeturebdd();
    std::vector<std::string> recuperer_compte_utilisateur(std::string mail);
};

#endif // GESTIONNAIREBDD_HPP
