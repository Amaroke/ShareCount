#ifndef CONNEXIONBDD_HPP
#define CONNEXIONBDD_HPP

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>

class ConnexionBDD : public QSqlDatabase
{
private:
    QSqlDatabase db;
public:
    /// @brief Créé la base de données de type et nom donné.
    ///
    /// @param type le type de la base de données.
    /// @param nom le nom de la base de données.
    ConnexionBDD(QSqlDatabase db);

    /// @brief Execute la séquence de requêtes données dans un fichier
    /// (une par ligne) et retourne la dernière requête exécutée.
    ///
    /// La séquence s'arrête quand une requête génère une erreur
    /// ou quand la dernière ligne du fichier est lue.
    ///
    /// @param file le fichier contenant les requêtes SQL.
    ///
    /// @return la dernière requête exécutée.
    void exec_file(QFile& file);

};

#endif /// CONNEXIONBDD_HPP
