/** @file connexion.hpp
 **
 ** @brief Le fichier qui contient la classe Connexion.
 **
 ** @version 4
 **
 ** @author H. Iopeti, univ. Lorraine
 **/

#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDialog>

namespace Ui {
class Connexion;
}

/** @brief La classe Connexion gère l'UI de la connexion de l'utilisateur
 **
 ** Elle contient 1 méthode de construction, 1 méthode de destruction
 ** et 4 fonctions.
 **
 ** @version 4
 **
 ** @author H. Iopeti, univ. Lorraine
 **/

class Connexion : public QDialog
{
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = nullptr);
    /// @brief Destructeur de la classe, ne fait rien.
    ~Connexion();

private slots:
    /// @brief La fonction associée à un clique de bouton annuler.
    void on_annuler_clicked();
    /// @brief La fonction associée à un clique de bouton creer un compte.
    void on_creer_un_compte_clicked();
    /// @brief La fonction associée à un clique de bouton mot de passe oublié.
    void on_mdp_oublie_clicked();
    /// @brief La fonction associée à un clique de bouton valider.
    void on_valider_clicked();

private:
    Ui::Connexion *ui;
};

#endif // CONNEXION_H
