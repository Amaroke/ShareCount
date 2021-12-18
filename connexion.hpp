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

#include "accueil.hpp"
#include "ui_connexion.h"
#include <QDialog>
#include <iostream>
#include <regex>

namespace Ui {
class Connexion;
}

/** @brief La classe Connexion gère l'UI de la connexion de l'utilisateur
 **
 ** Elle contient 2 méthodes de construction, 1 méthode de destruction
 ** et 5 fonctions.
 **
 ** @version 4
 **
 ** @author H. Iopeti, univ. Lorraine
 **/

class Connexion : public QDialog {
    Q_OBJECT

public:
    /// @brief Constructeur de la classe Connexion.
    explicit Connexion(QWidget* parent = nullptr);
    /// @brief Constructeur de la classe Connexion. @version 5 @author L. Yvoz, univ. Lorraine
    ///
    /// @param parent Le parent graphique de la fenêtre
    /// @param adresse_mail L'adresse mail de l'utilisateur
    /// @param mot_de_passe Le mot de passe de l'utilisateur
    /// @param utilisateur_existe Existence de l'utilisateur
    Connexion(QWidget* parent, const std::string& adresse_mail, const std::string& mot_de_passe, const bool utilisateur_existe);
    /// @brief Destructeur de la classe, ne fait rien.
    ~Connexion();
    /// @brief Fonction permettant de récupérer les informations rentrée par l'utilisateur. @version 5 @author L. Yvoz, univ. Lorraine
    ///
    /// @param adresse_mail un pointeur contenant l'adresse vers le string de l'adresse mail donnée
    /// @param mot_de_passe un pointeur contenant l'adresse vers le string du mot de passe donné
    void getDonnees(std::string& adresse_mail, std::string& mot_de_passe);

private slots:
    /// @brief La fonction associée à un clic de bouton annuler.
    void on_annuler_clicked();
    /// @brief La fonction associée à un clic de bouton creer un compte.
    void on_creer_un_compte_clicked();
    /// @brief La fonction associée à un clic de bouton mot de passe oublié.
    void on_mdp_oublie_clicked();
    /// @brief La fonction associée à un clic de bouton valider.
    void on_valider_clicked();

private:
    Ui::Connexion* ui;
};

#endif // CONNEXION_H
