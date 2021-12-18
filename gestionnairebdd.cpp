/* gestionnairebdd.cpp
 * version 11
 * H.Iopeti, univ. Lorraine
 */

#include "gestionnairebdd.hpp"

// Constructeur de la classe.
//
// bdd la base de données que l'on va modifier et utiliser.
GestionnaireBDD::GestionnaireBDD()
{
    //Création de la base de données
    QSqlDatabase bdd = QSqlDatabase::addDatabase("QSQLITE");

    bdd.setDatabaseName("bdd.db");
    if (bdd.open()) {
        QSqlQuery query(bdd);
        if (query.exec("CREATE TABLE IF NOT EXISTS utilisateur(mail VARCHAR(50) not null unique,mdp  VARCHAR(50) not null,nom  VARCHAR(50), primary key(mail));")) {
            query.finish();
            query.exec("INSERT INTO utilisateur VALUES ('henriette@orange.fr','05121990','Henriette');");
            query.finish();
            query.exec("INSERT INTO utilisateur VALUES ('claude@sfr.fr','JeSuisClaude54','Claude');");
            query.finish();
            query.exec("INSERT INTO utilisateur VALUES ('cunegonde@free.fr','88McGyver','Cunégonde');");
            query.finish();
            query.exec("INSERT INTO utilisateur VALUES ('patrocle@gmail.com','Troie','Patrocle');");
            query.finish();
            query.exec("INSERT INTO utilisateur VALUES ('octavie@orange.fr','CésarLeJeune','Octavie');");
            query.finish();
            query.exec("INSERT INTO utilisateur VALUES ('jeannic@sfr.fr','Dofus4life','Jeannic');");
            query.finish();
        } else {
            qDebug() << "Impossible de créer la table utilisateur";
            query.finish();
        }
        if (query.exec("CREATE TABLE IF NOT EXISTS compte(createur VARCHAR(50),nomc VARCHAR(50) PRIMARY KEY,type INT);")) {
            query.finish();
            query.exec("INSERT INTO compte VALUES ('henriette@orange.fr','Compte Henriette',1);");
            query.finish();
            query.exec("INSERT INTO compte VALUES ('claude@sfr.fr','Compte Claude',2);");
            query.finish();
            query.exec("INSERT INTO compte VALUES ('cunegonde@free.fr','Compte Cunégonde',3);");
            query.finish();
            query.exec("INSERT INTO compte VALUES ('patrocle@gmail.com','Compte Patrocle',1);");
            query.finish();
            query.exec("INSERT INTO compte VALUES ('octavie@orange.fr','Compte Octavie',3);");
            query.finish();
            query.exec("INSERT INTO compte VALUES ('jeannic@sfr.fr','Compte Jeannic',2);");
            query.finish();
        } else {
            qDebug() << "Impossible de créer la table compte";
            query.finish();
        }
        if (query.exec("CREATE TABLE IF NOT EXISTS participants(utilisateur VARCHAR(50),compte VARCHAR(50), PRIMARY KEY(utilisateur, compte));")) {
            query.finish();
            query.exec("INSERT INTO participants VALUES ('henriette@orange.fr','Compte Henriette');");
            query.finish();
            query.exec("INSERT INTO participants VALUES ('patrocle@gmail.com','Compte Henriette');");
            query.finish();
            query.exec("INSERT INTO participants VALUES ('cunegonde@free.fr','Compte Henriette');");
            query.finish();
            query.exec("INSERT INTO participants VALUES ('cunegonde@free.fr','Compte Claude');");
            query.finish();
            query.exec("INSERT INTO participants VALUES ('claude@sfr.fr','Compte Henriette');");
            query.finish();
            query.exec("INSERT INTO participants VALUES ('claude@sfr.fr','Compte Claude');");
            query.finish();
            query.exec("INSERT INTO participants VALUES ('cunegonde@free.fr','Compte Cunégonde');");
            query.finish();
            query.exec("INSERT INTO participants VALUES ('patrocle@gmail.com','Compte Patrocle');");
            query.finish();
            query.exec("INSERT INTO participants VALUES ('octavie@orange.fr','Compte Octavie');");
            query.finish();
            query.exec("INSERT INTO participants VALUES ('jeannic@sfr.fr','Compte JeanNic');");
            query.finish();
        } else {
            qDebug() << "Impossible de créer la table participants";
            query.finish();
        }
        if (query.exec("CREATE TABLE IF NOT EXISTS transac(id INT PRIMARY KEY, nomC VARCHAR(50), donneur VARCHAR(50), receveur VARCHAR(50), montant INT);")) {
            query.finish();
            query.exec("INSERT INTO transac VALUES (1,'Compte Henriette','claude@sfr.fr', NULL,100);");
            query.finish();
            query.exec("INSERT INTO transac VALUES (15,'Compte Henriette','cunegonde@free.fr', 'claude@sfr.fr', 50);");
            query.finish();
            query.exec("INSERT INTO transac VALUES (16,'Compte Henriette','patrocle@gmail.com', 'claude@sfr.fr', 50);");
            query.finish();
            query.exec("INSERT INTO transac VALUES (2,'Compte Claude','cunegonde@free.fr',NULL,50);");
            query.finish();
            query.exec("INSERT INTO transac VALUES (3,'Compte Cunégonde','patrocle@gmail.com',NULL,160);");
            query.finish();
            query.exec("INSERT INTO transac VALUES (18,'Compte Cunégonde',NULL,'cunegonde@free.fr',-160);");
            query.finish();
            query.exec("INSERT INTO transac VALUES (4,'Compte Patrocle','octavie@orange.fr','patrocle@gmail.com',300);");
            query.finish();
            query.exec("INSERT INTO transac VALUES (5,'Compte Octavie','jeannic@sfr.fr',NULL,600);");
            query.finish();
            query.exec("INSERT INTO transac VALUES (6,'Compte JeanNic','henriette@orange.fr',NULL,1200);");
            query.finish();
        } else {
            qDebug() << "Impossible de créer la table transaction";
            query.finish();
        }
    } else {
        qDebug() << "Ouverture de la base de données impossible";
    }
    bdd.close();
}

// Fonction qui ajoute un utilisateur à la base de données.
//
// utilisateur utilisateur à ajouter
// retourne un booléen qui vaut vrai si l'utilisateur à bien été ajouté
//
// version 12 Ludovic Yvoz, univ. Lorraine
bool GestionnaireBDD::ajouterUtilisateur(Utilisateur utilisateur)
{
    QSqlDatabase bdd = QSqlDatabase::database();
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

// Fonction qui recherche un utilisateur dans la base de donnée.
//
// mail le mail de l'utilisateur recherché
// retourne un utilisateur trouvé ou un utilisateur vide si il n'existe pas de correspondant
//
// version 12 Ludovic Yvoz, univ. Lorraine
Utilisateur GestionnaireBDD::recherche_utilisateur(const QString& mail)
{
    QSqlDatabase bdd = QSqlDatabase::database();
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

// Fonction qui ajoute un compte à la base de données.
//
// compte le compte à ajouter
//
// version 13 H. Mathieu Steinbach, univ. Lorraine
void GestionnaireBDD::ajouter_compte_bdd(const std::string email, const std::string nom_compte, int type)
{
    QSqlDatabase bdd = QSqlDatabase::database();
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
        if (query.exec("INSERT INTO participants VALUES ('" + mail + "','" + nom + "');")) {
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

Compte GestionnaireBDD::recherche_compte(const QString& compte)
{
    QSqlDatabase bdd = QSqlDatabase::database();
    Compte res = Compte(Utilisateur("", "", ""), "", -1);
    if (bdd.open()) {
        QSqlQuery query(bdd);
        if (query.exec("SELECT * FROM compte WHERE LOWER(nomc)=LOWER('" + compte + "');")) {
            while (query.next()) {
                res = Compte(recherche_utilisateur(query.value(0).toString().toStdString().c_str()), query.value(1).toString().toStdString(), query.value(2).toString().toInt());
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

// Fonction qui retourne la liste des comptes lié à un utilisateur.
//
// mail l'adresse mail à partir de laquelle la recherche s'effectue
//
// la liste des noms des comptes
//
// version 15 @author H. Mathieu Steinbach, univ. Lorraine
std::vector<std::string> GestionnaireBDD::recuperer_compte_utilisateur(const std::string mail)
{
    std::vector<std::string> res;

    QSqlDatabase bdd = QSqlDatabase::database();
    if (bdd.open()) {
        QSqlQuery query(bdd);
        QString email = QString(mail.c_str());
        if (query.exec("SELECT compte FROM participants WHERE LOWER(utilisateur)=LOWER('" + email + "');")) {
            while (query.next()) {
                res.push_back(query.value(0).toString().toStdString());
            }
            query.finish();
        } else {
            qDebug() << "Impossible de récupérer les comptes depuis la base de données";
            query.finish();
        }
    } else {
        qDebug() << "Ouverture de la base de données impossible";
    }
    bdd.close();

    return res;
}

// Procédure qui ajoute une transaction à la base de données.
//
// id l'identifiant de la transaction
// nom_compte le nom du comte sur lequel se déroule la la transaction
// donneur l'addresse mail de l'utilisateur initiant la transaction
// receveur l'addresse mail de l'utilisateur initiant la transaction
// montant le montant de la transaction
void GestionnaireBDD::ajouter_transaction(const int id, const std::string nom_compte, const std::string donneur, const std::string receveur, const int montant)
{
    QSqlDatabase bdd = QSqlDatabase::database();
    if (bdd.open()) {
        QSqlQuery query(bdd);
        QString id_str = QString(std::to_string(id).c_str());
        QString compte = QString(nom_compte.c_str());
        QString mail_donneur = QString(donneur.c_str());
        QString mail_receveur = QString(receveur.c_str());
        QString montant_str = QString(std::to_string(montant).c_str());
        if (mail_donneur == "NULL") {
            if (query.exec("INSERT INTO transac VALUES (" + id_str + ",'" + compte + "', NULL,'" + mail_receveur + "'," + montant_str + ");")) {
                query.finish();
            } else {
                qDebug() << "Impossible d'insérer la transaction dans la base de données";
                query.finish();
            }
        } else if (mail_receveur == "NULL") {
            if (query.exec("INSERT INTO transac VALUES (" + id_str + ",'" + compte + "','" + mail_donneur + "', NULL," + montant_str + ");")) {
                query.finish();
            } else {
                qDebug() << "Impossible d'insérer la transaction dans la base de données";
                query.finish();
            }
        } else {
            if (query.exec("INSERT INTO transac VALUES (" + id_str + ",'" + compte + "','" + mail_donneur + "','" + mail_receveur + "'," + montant_str + ");")) {
                query.finish();
            } else {
                qDebug() << "Impossible d'insérer la transaction dans la base de données";
                query.finish();
            }
        }
    } else {
        qDebug() << "Ouverture de la base de données impossible";
    }
    bdd.close();
}

// Procédure de suppression d'un compte.
void GestionnaireBDD::supprimer_compte(const QString nom, const QString utilisateur_connecte)
{
    QSqlDatabase bdd = QSqlDatabase::database();
    if (bdd.open()) {
        QSqlQuery query(bdd);
        if (query.exec("DELETE FROM compte WHERE(nomc='" + nom + "') AND(createur='" + utilisateur_connecte + "'));")) {
            query.finish();
        } else {
            qDebug() << "Impossible de supprimer des données dans la base de données";
            query.finish();
        }
        if (query.exec("DELETE FROM participants WHERE(compte='" + nom + "');")) {
            query.finish();
        }
    } else {
        qDebug() << "Ouverture de la base de données impossible";
    }
    bdd.close();
}

// Procédure qui ajoute un utilisateur à un compte de la base de données.
void GestionnaireBDD::ajouter_utilisateur_compte(const std::string mail, const std::string compte)
{
    QString nomc = QString(compte.c_str());
    QString email = QString(mail.c_str());
    QSqlDatabase bdd = QSqlDatabase::database();
    if (bdd.open()) {
        QSqlQuery query(bdd);
        if (query.exec("INSERT INTO participants VALUES ('" + email + "','" + nomc + "');")) {
            query.finish();
        } else {
            qDebug() << "Impossible d'ajouter un utilisateur à un compte";
            query.finish();
        }
    } else {
        qDebug() << "Ouverture de la base de données impossible";
    }
    bdd.close();
}

// Procédure qui ferme la connection à la base de données.
void GestionnaireBDD::fermeturebdd()
{
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
}

// Fonction qui retourne la liste des membres lié à un utilisateur.
//
// compte le compte à partir duquel la recherche s'effectue
//
// la liste des membres d'un compte
//
// version 19 @author H. Iopeti, univ. Lorraine
std::vector<std::string> GestionnaireBDD::recuperer_liste_membres(const std::string compte)
{
    std::vector<std::string> res;

    QSqlDatabase bdd = QSqlDatabase::database();
    if (bdd.open()) {
        QSqlQuery query(bdd);
        QString account = QString(compte.c_str());
        if (query.exec("SELECT utilisateur FROM participants WHERE LOWER(compte)=LOWER('" + account + "');")) {
            while (query.next()) {
                res.push_back(query.value(0).toString().toStdString());
            }
            query.finish();
        } else {
            qDebug() << "Impossible de récupérer la liste des membres depuis la base de données";
            query.finish();
        }
    } else {
        qDebug() << "Ouverture de la base de données impossible";
    }
    bdd.close();

    return res;
}

// Fonction qui retourne la liste des transactions liées à un compte utilisateur.
//
// compte le compte à partir duquel la recherche s'effectue
//
// la liste des transactions d'un compte
//
// version 19 @author H. Iopeti, univ. Lorraine
std::vector<std::string> GestionnaireBDD::recuperer_liste_transactions(const std::string compte)
{
    std::vector<std::string> res;

    QSqlDatabase bdd = QSqlDatabase::database();
    if (bdd.open()) {
        QSqlQuery query(bdd);
        QString account = QString(compte.c_str());
        if (query.exec("SELECT donneur, receveur, montant FROM transac WHERE LOWER(nomC)=LOWER('" + account + "');")) {
            while (query.next()) {
                std::string donnees;
                donnees.append(query.value(0).toString().toStdString()).append(" ").append(query.value(1).toString().toStdString()).append(" ").append(query.value(2).toString().toStdString());
                res.push_back(donnees);
            }
            query.finish();
        } else {
            qDebug() << "Impossible de récupérer la liste des transactions depuis la base de données";
            query.finish();
        }
    } else {
        qDebug() << "Ouverture de la base de données impossible";
    }
    bdd.close();

    return res;
}

//Fonction qui recherche le createur d'un compte dans la base de données à partir d'un nom de compte
//
// compte le nom à partir duquel la recherche s'effectue
//
// l'utilisateur trouvé ou un utilisateur avec des données vides si aucun utilisateur n'a été trouvé
// version 22, L. Yvoz, univ. Lorraine
Utilisateur GestionnaireBDD::recherche_createur(const QString& compte)
{
    QSqlDatabase bdd = QSqlDatabase::database();
    Utilisateur res = Utilisateur("", "", "");
    if (bdd.open()) {
        QSqlQuery query(bdd);
        if (query.exec("SELECT createur FROM compte WHERE LOWER(nomc)=LOWER('" + compte + "');")) {
            while (query.next()) {
                res = recherche_utilisateur(query.value(0).toString().toStdString().c_str());
            }
            query.finish();
        } else {
            qDebug() << "Impossible de retrouver le créateur du compte dans la base de données";
            query.finish();
        }
    } else {
        qDebug() << "Ouverture de la base de données impossible";
    }
    bdd.close();
    return res;
}
