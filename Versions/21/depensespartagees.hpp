#ifndef DEPENSESPARTAGEES_HPP
#define DEPENSESPARTAGEES_HPP

#include <QDialog>
#include <gestionnairedialogue.hpp>

namespace Ui {
class DepensesPartagees;
}

class DepensesPartagees : public QDialog
{
    Q_OBJECT

public:
    /// @brief Constructeur de la classe CompteCommun.
    /// @param QWidget parent
    explicit DepensesPartagees(QWidget *parent = nullptr);
    /// @brief Constructeur de la classe DepensesPartagees.
    /// @param QWidget parent
    /// @param Compte compte
    DepensesPartagees(QWidget* parent, const std::string compte, const GestionnaireDialogue& gd);
    ~DepensesPartagees();
    /// @brief La fonction associée à un raffraichissement de la fenêtre du compte de dépenses partagées.
    /// @version 20 @author H. Mathieu Steinbahc, univ. Lorraine
    void raffraichir_affichage();

private slots:
    /// @brief La procédure qui gère le bouton retour.
    void on_retour_clicked();
/// @brief La procédure qui gère l'enregistrement d'une transaction après une action sur le bouton correspondant.
    void on_enregistrer_clicked();

private:
    Ui::DepensesPartagees *ui;
    /// @brief Le gestionnaire de dialogue de l'application.
    GestionnaireDialogue gestionnaire;
    /// @brief Le compte depuis lequel on invite.
    std::string compte;
};

#endif // DEPENSESPARTAGEES_HPP
