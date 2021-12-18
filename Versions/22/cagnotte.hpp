/** @file cagnotte.hpp
 **
 ** @brief Le fichier qui contient la classe Cagnotte.
 **
 ** @version 22
 **
 ** @author L. Yvoz, univ. Lorraine
 **/

#ifndef CAGNOTTE_HPP
#define CAGNOTTE_HPP

#include <QDialog>
#include "gestionnairedialogue.hpp"

namespace Ui {
class Cagnotte;
}

class Cagnotte : public QDialog
{
    Q_OBJECT

public:
    /// @brief Constructeur de la classe Cagnotte.
    /// @param QWidget parent
    explicit Cagnotte(QWidget *parent = nullptr);
    /// @brief Constructeur de la classe Cagnotte.
    /// @param QWidget parent
    /// @param Compte compte
    /// @param gd gestionnaire de dialogue
    Cagnotte(QWidget* parent, const std::string compte, const GestionnaireDialogue& gd);
    /// @brief Destructeur de la classe, ne fait rien.
    ~Cagnotte();

private slots:
    /// @brief La procédure associée à un clic de bouton retour.
    void on_retour_clicked();
    /// @brief La procédure associée à un clic de bouton retirer de l'argent.
    void on_retirerDeLArgent_clicked();
    /// @brief La procédure associée à un clic de bouton déposer de l'argent.
    void on_deposerDeLArgent_clicked();

private:
    Ui::Cagnotte *ui;
    /// @brief Le gestionnaire de dialogue de l'application.
    GestionnaireDialogue gestionnaire;
    /// @brief Le compte depuis que l'on regarde.
    std::string compte;
    /// @brief La fonction associée à un raffraichissement de la fenêtre de la cagnotte.
    ///
    /// @return le montant total d'argent dans la cagnotte
    int raffraichir_affichage();
};

#endif // CAGNOTTE_HPP
