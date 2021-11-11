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
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    bool connexion_utilisateur(std::string adresse_mail,
                               std::string mot_de_passe);
    void fenetre_creer_un_compte();
    void fenetre_se_connecter();

private slots:
    void on_creer_compte_clicked();
    void on_se_connecter_clicked();
    void on_afficher_connecter_clicked();

private:
    Ui::MainWindow* ui;
    GestionnaireDialogue gestionnaire_dialogue;
};

#endif // MAINWINDOW_H
