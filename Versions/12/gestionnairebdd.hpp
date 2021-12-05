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

#include <QtSql>
#include <QTableView>
#include <QFileDialog>
#include "utilisateur.hpp"

class GestionnaireBDD
{
private:
    QSqlDatabase bdd;
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
};

#endif // GESTIONNAIREBDD_HPP
