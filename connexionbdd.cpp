#include "connexionbdd.hpp"


// Créé la base de données de type et nom donné.
//
// type le type de la base de données.
// nom le nom de la base de données.
ConnexionBDD::ConnexionBDD(QSqlDatabase db) :
    db(db)
{
}

// Execute la séquence de requêtes données dans un fichier
// (une par ligne) et retourne la dernière requête exécutée.
//
// La séquence s'arrête quand une requête génère une erreur
// ou quand la dernière ligne du fichier est lue.
//
// file le fichier contenant les requêtes SQL.
//
// la dernière requête exécutée.
void ConnexionBDD::exec_file(QFile& file) {
    // la requête utilise la base de données données à la construction
    if (db.open()) {
        printf("AAAAAAAA\n");
        fflush(stdout);
        QSqlQuery result(db);
        printf("AAAAAAAA\n");
        fflush(stdout);
        if ( ( file.isOpen() && file.isReadable() )
             || file.open(QIODevice::ReadOnly) ) {
            printf("while  : %s \n",lastError().text().toStdString().c_str());
            fflush(stdout);
            while (  (! file.atEnd() ) ) {
                printf("aaaaaaa\n");
                fflush(stdout);
                // lis la requête dans le fichier et l'éxecute
                QString s(file.readLine(1000));
                printf("requete : %s\n", s.toStdString().c_str());
                fflush(stdout);
                result.exec(s);

            }
            file.close();
        }
    }
}
