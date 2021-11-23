#include "fenetreutilisateur.hpp"
#include "ui_fenetreutilisateur.h"

FenetreUtilisateur::FenetreUtilisateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetreUtilisateur)
{
    ui->setupUi(this);
}


FenetreUtilisateur::FenetreUtilisateur(QWidget* parent, GestionnaireDialogue gd)
    : QMainWindow(parent)
    , ui(new Ui::FenetreUtilisateur),
      gestionnaire_dialogue(gd)
{
    ui->setupUi(this);
}

FenetreUtilisateur::~FenetreUtilisateur()
{
    delete ui;
}

