#ifndef FENETREUTILISATEUR_HPP
#define FENETREUTILISATEUR_HPP

#include <QMainWindow>
#include "gestionnairedialogue.hpp"

namespace Ui {
class FenetreUtilisateur;
}

class FenetreUtilisateur : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetreUtilisateur(QWidget *parent = nullptr);
    ~FenetreUtilisateur();
    /// @brief Constructeur de la classe FenetreUtilisateur.
    /// @param QWidget parent
    FenetreUtilisateur(QWidget *parent,GestionnaireDialogue gd);

private slots:
    void on_pushButton_clicked();

private:
    Ui::FenetreUtilisateur *ui;
    /// @brief Le gestionnaire de dialogue de l'application.
    GestionnaireDialogue gestionnaire_dialogue;
};

#endif // FENETREUTILISATEUR_HPP
