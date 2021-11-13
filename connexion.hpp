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

#include "mainwindow.hpp"
#include "ui_connexion.h"
#include <QDialog>
#include <iostream>
#include <regex>

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

class Connexion : public QDialog {
    Q_OBJECT

public:
    explicit Connexion(QWidget* parent = nullptr);
    Connexion(QWidget* parent, std::string adresse_mail, std::string mot_de_passe, bool utilisateur_existe);
    /// @brief Destructeur de la classe, ne fait rien.
    ~Connexion();
    /// @brief Fonction permettant de récupérer les informations rentrée par l'utilisateur
    ///
    /// @param adresse_mail un pointeur contenant l'adresse vers le string de l'adresse mail donnée
    /// @param mot_de_passe un pointeur contenant l'adresse vers le string du mot de passe donné
    void getDonnees(std::string& adresse_mail, std::string& mot_de_passe);

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
    Ui::Connexion* ui;
};

#endif // CONNEXION_H
