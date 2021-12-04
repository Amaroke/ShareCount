#include "accueil.hpp"
#include "connexionbdd.hpp"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Accueil w;
    w.show();
    //Création de la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../ShareCount/database/data.db");
    db.open();
    QSqlQuery query(db);
    query.exec("CREATE OR REPLACE TABLE utilisateur(mail VARCHAR(50) PRIMARY KEY,mdp  VARCHAR(50),nom  VARCHAR(50));");
    query.exec("INSERT INTO utilisateur VALUES ('Henriette@orange.fr','05121990','Henriette');");
    query.exec("INSERT INTO utilisateur VALUES ('Claude@sfr.fr','JeSuisClaude54','Claude');");
    query.exec("INSERT INTO utilisateur VALUES ('Cunégonde@free.fr','88McGyver','Cunégonde');");
    query.exec("INSERT INTO utilisateur VALUES ('Patrocle@gmail.com','Troie','Patrocle');");
    query.exec("INSERT INTO utilisateur VALUES ('Octavie@orange.fr','CésarLeJeune','Octavie');");
    query.exec("CREATE OR REPLACE TABLE compte(nomc VARCHAR(50) PRIMARY KEY,createur VARCHAR(50),type INT);");
    query.exec("INSERT INTO compte VALUES ('Henriette@orange.fr','Compte Henriette',1);");
    query.exec("INSERT INTO compte VALUES ('Claude@sfr.fr','Claude',2);");
    query.exec("INSERT INTO compte VALUES ('Cunégonde@free.fr','Cunégonde',3);");
    query.exec("INSERT INTO compte VALUES ('Patrocle@gmail.com','Patrocle',1);");
    query.exec("INSERT INTO compte VALUES ('Octavie@gmail.com','Octavie',3);");
    query.exec("CREATE OR REPLACE TABLE participants(utilisateur VARCHAR(50),compte VARCHAR(50));");
    query.exec("INSERT INTO participants VALUES ('Henriette@orange.fr','Compte Henriette');");
    /*query.exec("SELECT mail FROM utilisateur;");
    printf("resultat : %s\n", query.value(0).toString().toStdString().c_str());
    fflush(stdout);*/
    /*ConnexionBDD connexionBDD(db);
    QFile fichier("../ShareCount/database/shareCountBDD.sqlite");
    connexionBDD.exec_file(fichier);*/
    return a.exec();
}
