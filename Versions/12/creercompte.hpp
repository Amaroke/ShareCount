/** @file creercompte.hpp
 **
 ** @brief Le fichier qui contient la classe CreerCompte.
 **
 ** @version 10
 **
 ** @author H. Mathieu Steinbach, univ. Lorraine
 **/

#ifndef CREERCOMPTE_HPP
#define CREERCOMPTE_HPP

#include <QDialog>

namespace Ui {
class CreerCompte;
}
/** @brief La classe Invitation gère l'UI de la creation d'un compte
 **
 ** Elle contient 1 méthode de construction, 1 méthode de destruction
 ** et 3 fonctions.
 **
 ** @version 10
 **
 ** @author H. Mathieu Steinbach, univ. Lorraine
 **/
class CreerCompte : public QDialog
{
    Q_OBJECT

public:
    /// @brief Constructeur de la classe par défaut.
    explicit CreerCompte(QWidget *parent = nullptr);
    /// @brief Destructeur de la classe.
    ~CreerCompte();
    /// @brief Fonction permettant de récupérer les informations rentrée par l'utilisateur.
    ///
    /// @param adresse_mail un pointeur contenant l'adresse vers le string du nom donné
    /// @param choix un pointeur contenant l'adresse vers le choix de type de compte
    void getDonnees(std::string& nom, int& choix);

private slots:
    /// @brief La fonction associée à un clic de bouton Annuler.
    void on_annuler_clicked();
    /// @brief La fonction associée à un clic de bouton Valider.
    void on_valider_clicked();

private:
    Ui::CreerCompte *ui;
};

#endif // CREERCOMPTE_HPP
