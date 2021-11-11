/** @file inscription.hpp
 **
 ** @brief Le fichier qui contient la classe Inscription.
 **
 ** @version 2
 **
 ** @author H. Mathieu Steinbach, univ. Lorraine
 **/

#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QDialog>

namespace Ui {
class Inscription;
}

/** @brief La classe Inscription gère l'UI de création de compte et la validité des données sasisies.
 **
 ** Elle contient 1 méthode de construction, 1 méthode de destruction
 ** et 2 fonctions.
 **
 ** @version 2
 **
 ** @author H. Mathieu Steinbach, univ. Lorraine
 **/

class Inscription : public QDialog
{
    Q_OBJECT

public:
    explicit Inscription(QWidget *parent = nullptr);
    /// @brief Destructeur de la classe, ne fait rien.
    ~Inscription();

private slots:
    /// @brief La fonction associée à un clique de bouton valider.
    void on_validation_accepted();
    /// @brief La fonction associée à un clique du bouton annuler.
    void on_validation_rejected();

private:
    Ui::Inscription *ui;
};

#endif // INSCRIPTION_H
