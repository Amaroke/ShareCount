/** @file invitation.hpp
 **
 ** @brief Le fichier qui contient la classe Invitation.
 **
 ** @version 8
 **
 ** @author H. Iopeti, univ. Lorraine
 **/

#ifndef INVITATION_H
#define INVITATION_H

#include <QDialog>
#include <regex>
#include <iostream>
#include <gestionnairedialogue.hpp>
#include "ui_invitation.h"
#include "string.h"

namespace Ui {
class Invitation;
}

/** @brief La classe Invitation gère l'UI de l'invitation d'un utilisateur
 **
 ** Elle contient 1 méthode de construction, 1 méthode de destruction
 ** et 3 fonctions.
 **
 ** @version 8
 **
 ** @author H. Iopeti, univ. Lorraine
 **/

class Invitation : public QDialog
{
    Q_OBJECT

public:
    /// @brief Constructeur de la classe Invitation.
    /// @param QWidget parent
    explicit Invitation(QWidget *parent = nullptr);
    /// @brief Constructeur de la classe Invitation.
    /// @param QWidget parent
    /// @param Compte compte
    Invitation(QWidget *parent,Compte compte);
    /// @brief Destructeur de la classe, ne fait rien.
    ~Invitation();

private slots:
    /// @brief La fonction associée à un clic de bouton retour.
    void on_Retour_clicked();
    /// @brief La fonction associée à un clic de bouton envoyer à nouveau.
    void on_envoyer_a_nouveau_clicked();
    /// @brief La fonction associée à un clic de bouton valider.
    void on_valider_clicked();

private:
    Ui::Invitation *ui;
    GestionnaireDialogue gestionnaire;
    Compte compte;
};

#endif // INVITATION_H
