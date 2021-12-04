#include "gestionnairebdd.hpp"

// Constructeur de la classe.
//
// bdd la base de données que l'on va modifier et utiliser.
GestionnaireBDD::GestionnaireBDD() :
    bdd()
{
    //Création de la base de données
    QSqlDatabase bdd = QSqlDatabase::addDatabase("QSQLITE");
    bdd.setDatabaseName("../ShareCount/bdd.db");
    bdd.open();
    bdd.close();
}

