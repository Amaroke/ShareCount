/*#include "gestionnairebdd.hpp"

// Constructeur de la classe.
//
// bdd la base de données que l'on va modifier et utiliser.
GestionnaireBDD::GestionnaireBDD(QSqlDatabase& bdd) :
    bdd(bdd)
{
}

// Fonction qui recherche dans la base de données le mot de passe
// d'un utilisateur à partir de son email.
//
// email l'adresse mail donnée.
//
// le mot de passe recherché.
QString GestionnaireBDD::getMotDePasse(const QString& email) {
        QString mdp;
        const QString nomBDD = "UTILISATEUR";
        // Connexion à la base de données utilisateur
        ConnexionBDD connexionBDD("QSQLITE",  nomBDD.isNull() || nomBDD.isEmpty() ?
                ":memory:" : nomBDD);
        if ( connexionBDD.open() ) {
            if (bdd.tables().contains(email)) {
                QSqlQuery requete(bdd);
                requete.exec("SELECT mdp"
                             "FROM UTILISATEUR "
                             "WHERE LOWER(mail) = LOWER(" + email + ");");
                mdp = requete.value(0).toString();
                printf("mdp : %s",mdp.toStdString().c_str());
            }
        }
        return mdp;
}*/

