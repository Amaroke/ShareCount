/* gestionnairebdd.cpp
 * version 11
 * H.Iopeti, univ. Lorraine
 */

#include "gestionnairebdd.hpp"

// Constructeur de la classe.
//
// bdd la base de données que l'on va modifier et utiliser.
GestionnaireBDD::GestionnaireBDD()
    : bdd()
{
    //Création de la base de données
    bdd = QSqlDatabase::addDatabase("QSQLITE");

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
        if (query.exec("CREATE TABLE IF NOT EXISTS participants(utilisateur VARCHAR(50),compte VARCHAR(50));")) {
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

// Fonction qui ajoute un utilisateur à la base de données
//
// utilisateur utilisateur à ajouter
// retourne un booléen qui vaut vrai si l'utilisateur à bien été ajouté
//
// version 12 Ludovic Yvoz, univ. Lorraine
bool GestionnaireBDD::ajouterUtilisateur(Utilisateur utilisateur)
{
    bool res = false;
    if (bdd.open()) {
        QSqlQuery query(bdd);
        QString mail = QString(utilisateur.get_adresse_mail().c_str());
        QString mdp = QString(utilisateur.get_mot_de_passe().c_str());
        QString nom = QString(utilisateur.get_nom_utilisateur().c_str());
        if (query.exec("INSERT INTO utilisateur VALUES ('" + mail + "','" + mdp + "','" + nom + "');")) {
            query.finish();
            res = true;
        } else {
            qDebug() << "Impossible d'insérer l'utilisateur dans la base de données";
            query.finish();
        }
    } else {
        qDebug() << "Ouverture de la base de données impossible";
    }
    bdd.close();
    return res;
}

// Fonction qui recherche un utilisateur dans la base de donnée
//
// mail le mail de l'utilisateur recherché
// retourne un utilisateur trouvé ou un utilisateur vide si il n'existe pas de correspondant
//
// version 12 Ludovic Yvoz, univ. Lorraine
Utilisateur GestionnaireBDD::recherche_utilisateur(const QString& mail)
{
    Utilisateur res = Utilisateur("", "", "");
    if (bdd.open()) {
        QSqlQuery query(bdd);
        if (query.exec("SELECT * FROM utilisateur WHERE LOWER(mail)=LOWER('" + mail + "');")) {
            while (query.next()) {
                res = Utilisateur(query.value(0).toString().toStdString(), query.value(1).toString().toStdString(), query.value(2).toString().toStdString());
            }
            query.finish();
        } else {
            qDebug() << "Impossible de retrouver l'utilisateur dans la base de données";
            query.finish();
        }
    } else {
        qDebug() << "Ouverture de la base de données impossible";
    }
    bdd.close();
    return res;
}

// Fonction qui ajoute un compte à la base de données
//
// compte le compte à ajouter
//
// version 13 H. Mathieu Steinbach, univ. Lorraine
void GestionnaireBDD::ajouter_compte_bdd(const std::string email, const std::string nom_compte, int type)
{
    if (bdd.open()) {
        QSqlQuery query(bdd);
        QString mail = QString(email.c_str());
        QString nom = QString(nom_compte.c_str());
        QString type_compte = QString(std::to_string(type).c_str());
        if (query.exec("INSERT INTO compte VALUES ('" + mail + "','" + nom + "'," + type_compte + ");")) {
            query.finish();
        } else {
            qDebug() << "Impossible d'insérer le compte dans la base de données";
            query.finish();
        }
    } else {
        qDebug() << "Ouverture de la base de données impossible";
    }
    bdd.close();
}

void GestionnaireBDD::fermeturebdd(){
    //TODO Réussir à fermer la connexion de la base de donnée.
}
