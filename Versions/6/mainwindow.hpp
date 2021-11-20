#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "connexion.hpp"
#include "gestionnairedialogue.hpp"
#include "inscription.hpp"
#include "ui_mainwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /// @brief Le constructeur de la classe.
    MainWindow(QWidget* parent = nullptr);
    /// @brief Le destructeur de la classe.
    ~MainWindow();
    /// @brief Fonction qui connecte un utilisateur à l'application en fonction de l'adresse mail et du mot de passe donné en paramètre. @version 5 @author L. Yvoz, univ. Lorraine
    ///
    /// @param adresse_mail l'adresse mail donnée
    /// @param mot_de_passe un pointeur contenant le mot de passe donné
    /// @param mdp_correct un pointeur vers un booléen qui indique si le mot de passe est correct
    ///
    /// @return Un booléen qui indique si l'utilisateur s'est connecté.
    bool connexion_utilisateur(std::string adresse_mail,
        std::string mot_de_passe,
        bool& mdp_correct);
    /// @brief Création d'une fenêtre de d'inscription depuis la mainwindows. @version 5 @author L. Yvoz, univ. Lorraine
    void fenetre_creer_un_compte();
    /// @brief Création d'une fenêtre de connexion depuis la mainwindows. @version 5 @author L. Yvoz, univ. Lorraine
    ///
    /// @param adresse_mail l'adresse mail donnée
    /// @param mot_de_passe un pointeur contenant le mot de passe donné
    /// @param utilisateur_existe un booléen qui contient l'information de l'existence du compte
    void fenetre_se_connecter(std::string adresse_mail = "", std::string mot_de_passe = "", bool utilisateur_existe = false);

private slots:
    /// @brief La fonction associée à un clic de bouton de création de compte.
    void on_creer_compte_clicked();
    /// @brief La fonction associée à un clic de bouton sur se connecter.
    void on_se_connecter_clicked();
    /// @brief La fonction associée à un clic de bouton sur afficher l'utilisateur connecté.
    void on_afficher_connecter_clicked();
    /// @brief La fonction associée à un clic de bouton sur quitter l'application. @version 6 @author H. Mathieu Steinbach, univ. Lorraine
    void on_quitter_appli_clicked();

private:
    Ui::MainWindow* ui;
    /// @brief Le gestionnaire de dialogue de l'application.
    GestionnaireDialogue gestionnaire_dialogue;
};

#endif // MAINWINDOW_H