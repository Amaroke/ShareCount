#include "inscription.h"
#include "ui_inscription.h"
#include <iostream>

Inscription::Inscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inscription)
{
    ui->setupUi(this);
}

Inscription::~Inscription()
{
    delete ui;
}

void Inscription::on_validation_accepted()
{
    std::cout << ui->saisie_mail->toPlainText().toStdString();
    this->accept();
}


void Inscription::on_validation_rejected()
{
    this->reject();
}

