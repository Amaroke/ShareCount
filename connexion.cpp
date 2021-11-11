/* inscription.cpp
 * version 4
 * H. Iopeti, univ. Lorraine
 */

#include "connexion.hpp"

// Constructeur de la classe Connexion.
Connexion::Connexion(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Connexion)
{
    ui->setupUi(this);
}

// Destructeur de la classe Connexion.
Connexion::~Connexion() { delete ui; }

// En cas d'appui sur annuler.
void Connexion::on_annuler_clicked()
{
    this->reject(); // On ferme la fenêtre de dialogue.
}

void Connexion::on_creer_un_compte_clicked()
{
    this->reject(); // On ferme la fenêtre de dialogue.
}

void Connexion::on_mdp_oublie_clicked() { }

void Connexion::on_valider_clicked()
{
    // On récupère l'email saisi.
    std::string mail = ui->adresse_mail->toPlainText().toStdString();
    // On récupère le mot de passe saisi.
    std::string mdp = ui->mot_de_passe->toPlainText().toStdString();
    // On fait les vérifications sur l'email (syntaxe correcte).
    const std::regex pattern(
                "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); // Regex pour la validité d'un
    // mail.
    // On regarde si le pattern du mail match avec le mail saisi.
    bool mail_valide = std::regex_match(mail, pattern);

    // On teste si l'utilisateur saisi un paramètre et si la saisie est invalide.
    if (mail.length() > 0 && mdp.length() > 0 && mail_valide) {
        // Si le test est valide, on affiche sur la sortie standard le mail et le
        // mot de passe saisi.
        this->accept(); // On ferme le dialogue.
    } else {
        // Si le test est invalide, on affiche un message d'erreur sur la sortie
        // standard.
        std::cout << "Veuillez recommencer !\n";
    }
    fflush(stdout);
}
