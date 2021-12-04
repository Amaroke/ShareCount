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
