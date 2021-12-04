/*#ifndef GESTIONNAIREBDD_HPP
#define GESTIONNAIREBDD_HPP

#include <QtSql>
#include <QTableView>
#include <QFileDialog>
#include "connexionbdd.hpp"

class GestionnaireBDD
{
private:
    QSqlDatabase bdd;
public:
    /// @brief  Constructeur de la classe.
    ///
    /// @param  bdd la base de données que l'on va modifier et utiliser.
    GestionnaireBDD(QSqlDatabase& bdd);

    /// @brief Fonction qui recherche dans la base de données le mot de passe
    ///  d'un utilisateur à partir de son email.
    ///
    /// @param email l'adresse mail donnée.
    ///
    /// @return le mot de passe recherché.
    QString getMotDePasse(const QString& email);
};

#endif // GESTIONNAIREBDD_HPP*/
