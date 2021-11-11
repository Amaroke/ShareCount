#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestionnairedialogue.hpp"
#include "ui_mainwindow.h"
#include "connexion.hpp"
#include "inscription.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool connexion_utilisateur(std::string adresse_mail,std::string mot_de_passe);
    void fenetre_creer_un_compte();
    void fenetre_se_connecter();

private slots:
    void on_creer_compte_clicked();

private:
    Ui::MainWindow *ui;
    void afficher_dialog_inscription();
    GestionnaireDialogue gestionnaire_dialogue;
};

#endif // MAINWINDOW_H
