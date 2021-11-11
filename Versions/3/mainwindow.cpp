#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inscription.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_creer_compte_clicked()
{
    Inscription *inscription = new Inscription(this);
    inscription->setWindowTitle("Créer un compte");
    inscription->show();
}

