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

class GestionnaireBDD
{
private:
    QSqlDatabase bdd;
public:
    /// @brief  Constructeur de la classe.
    GestionnaireBDD();
};

#endif // GESTIONNAIREBDD_HPP
