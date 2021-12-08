#include "QSqlDatabase"
#include "QSqlQuery"
#include "accueil.hpp"
#include <QApplication>
#include <QFile>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Accueil w;
    w.show();
    return a.exec();
}
