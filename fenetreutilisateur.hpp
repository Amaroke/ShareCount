/** @file fenetreUtilisateur.hpp
 **
 ** @brief Le fichier qui contient la classe FenetreUtilisateur.
 **
 ** @version 9
 **
 ** @author H. Mathieu Steinbach, univ. Lorraine
 **/

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
    /// @brief Destructeur de la classe, ne fait rien.
    ~FenetreUtilisateur();
    /// @brief Constructeur de la classe FenetreUtilisateur.
    /// @param parent Le parent graphique
    /// @param gd Le GestionnaireDialogue de l'application.
    FenetreUtilisateur(QWidget *parent,GestionnaireDialogue gd);

private:
    Ui::FenetreUtilisateur *ui;
    /// @brief Le gestionnaire de dialogue de l'application.
    GestionnaireDialogue gestionnaire_dialogue;
};

#endif // FENETREUTILISATEUR_HPP
