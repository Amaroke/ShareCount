/** @file comptecommun.hpp
 **
 ** @brief Le fichier qui contient la classe CompteCommun.
 **
 ** @version 18
 **
 ** @author H. Iopeti, univ. Lorraine
 **/

#ifndef COMPTECOMMUN_HPP
#define COMPTECOMMUN_HPP

#include "gestionnairedialogue.hpp"
#include <QDialog>

namespace Ui {
class CompteCommun;
}

/** @brief La classe CompteCommun gère l'UI du compte commun d'un utilisateur
 **
 ** Elle contient 2 méthodes de construction, 1 méthode de destruction
 ** et 4 fonctions.
 **
 ** @version 18
 **
 ** @author H. Iopeti, univ. Lorraine
 **/

class CompteCommun : public QDialog {
    Q_OBJECT

public:
    /// @brief Constructeur de la classe CompteCommun.
    /// @param QWidget parent
    explicit CompteCommun(QWidget* parent = nullptr);
    /// @brief Constructeur de la classe CompteCommun.
    /// @param QWidget parent
    /// @param Compte compte
    CompteCommun(QWidget* parent, const std::string compte, const GestionnaireDialogue& gd);
    /// @brief Destructeur de la classe, ne fait rien.
    ~CompteCommun();

private slots:
    /// @brief La procédure associée à un clic de bouton retour.
    void on_retour_clicked();
    /// @brief La procédure associée à un clic de bouton retirer de l'argent.
    /// @version 20 @author H. Iopeti
    void on_retirerDeLArgent_clicked();
    /// @brief La procédure associée à un clic de bouton déposer de l'argent.
    /// @version 20 @author H. Iopeti
    void on_deposerDeLArgent_clicked();
    /// @brief La procédure associée à un raffraichissement de la fenêtre du compte commun.
    /// @version 20 @author H. Iopeti
    void raffraichir_affichage();

private:
    Ui::CompteCommun* ui;
    /// @brief Le gestionnaire de dialogue de l'application.
    GestionnaireDialogue gestionnaire;
    /// @brief Le compte depuis lequel on invite.
    std::string compte;
};

#endif // COMPTECOMMUN_HPP
