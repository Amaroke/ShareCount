/** @file gestionnairebdd.cpp
 **
 ** @brief Le fichier qui contient la classe GestionnaireBDD.
 **
 ** @version 11
 **
 ** @author H. Iopeti, univ. Lorraine
 **/

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

    if (bdd.open()) {
            QSqlQuery query(bdd);
            if (query.exec("CREATE TABLE IF NOT EXISTS utilisateur(mail VARCHAR(50) not null unique,mdp  VARCHAR(50) not null,nom  VARCHAR(50), primary key(mail));")) {
                query.finish();
                query.exec("INSERT INTO utilisateur VALUES ('Henriette@orange.fr','05121990','Henriette');");
                query.finish();
                query.exec("INSERT INTO utilisateur VALUES ('Claude@sfr.fr','JeSuisClaude54','Claude');");
                query.finish();
                query.exec("INSERT INTO utilisateur VALUES ('Cunégonde@free.fr','88McGyver','Cunégonde');");
                query.finish();
                query.exec("INSERT INTO utilisateur VALUES ('Patrocle@gmail.com','Troie','Patrocle');");
                query.finish();
                query.exec("INSERT INTO utilisateur VALUES ('Octavie@orange.fr','CésarLeJeune','Octavie');");
                query.finish();
                query.exec("INSERT INTO utilisateur VALUES ('Jeannic@sfr.fr','Dofus4life','Jeannic');");
                query.finish();
            } else {
                qDebug() << "Impossible de créer la table utilisateur";
                query.finish();
            }
            if (query.exec("CREATE TABLE IF NOT EXISTS compte(nomc VARCHAR(50) PRIMARY KEY,createur VARCHAR(50),type INT);")) {
                query.finish();
                query.exec("INSERT INTO compte VALUES ('Henriette@orange.fr','Compte Henriette',1);");
                query.finish();
                query.exec("INSERT INTO compte VALUES ('Claude@sfr.fr','Claude',2);");
                query.finish();
                query.exec("INSERT INTO compte VALUES ('Cunégonde@free.fr','Cunégonde',3);");
                query.finish();
                query.exec("INSERT INTO compte VALUES ('Patrocle@gmail.com','Patrocle',1);");
                query.finish();
                query.exec("INSERT INTO compte VALUES ('Octavie@orange.fr','Octavie',3);");
                query.finish();
                query.exec("INSERT INTO compte VALUES ('Jeannic@sfr.fr','Jeannic',2);");
                query.finish();
            } else {
                qDebug() << "Impossible de créer la table compte";
                query.finish();
            }
            if (query.exec("CREATE TABLE IF NOT EXISTS participants(utilisateur VARCHAR(50),compte VARCHAR(50));")){
                query.finish();
                query.exec("INSERT INTO participants VALUES ('Henriette@orange.fr','Compte Henriette');");
                query.finish();
                query.exec("INSERT INTO participants VALUES ('Claude@sfr.fr','Compte Claude');");
                query.finish();
                query.exec("INSERT INTO participants VALUES ('Cunégonde@free.fr','Compte Cunégonde');");
                query.finish();
                query.exec("INSERT INTO participants VALUES ('Patrocle@gmail.com','Compte Patrocle');");
                query.finish();
                query.exec("INSERT INTO participants VALUES ('Octavie@orange.fr','Compte Octavie');");
                query.finish();
                query.exec("INSERT INTO participants VALUES ('Jeannic@sfr.fr','Compte JeanNic');");
                query.finish();
            } else {
                qDebug() << "Impossible de créer la table participants";
                query.finish();
           }
        } else {
            qDebug() << "Ouverture de la base de données impossible";
        }
    bdd.close();
}

