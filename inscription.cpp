/* inscription.cpp
 * version 2
 * H. Mathieu Steinbach, univ. Lorraine
 */

#include "inscription.hpp"

// Constructeur de la classe Inscription.
Inscription::Inscription(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Inscription)
{
    ui->setupUi(this);
}

// Destructeur de la classe Inscription.
Inscription::~Inscription() { delete ui; }

// En cas d'appui sur valider.
void Inscription::on_validation_accepted()
{
    // On récupère l'email saisi.
    std::string mail = ui->saisie_mail->toPlainText().toStdString();
    // On fait les vérifications sur l'email (syntaxe correcte).
    const std::regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); // Regex pour la validité d'un
    // mail. (On check si le mail est composé de lettres, un @, des lettres, un ., des lettres.)
    bool mail_valide = std::regex_match(mail, pattern);

    // On récupère le mot de passe saisi.
    std::string mdp = ui->saisie_mdp->toPlainText().toStdString();
    // On fait les vérifications sur le mot de passe (nombre minimum de caractère
    // = 8).
    bool mdp_valide = mdp.length() >= 8;

    // On récupère la confirmation du mot de passe saisie.
    std::string confirmation_mdp = ui->saisie_confirm_mdp->toPlainText().toStdString();
    // On fait la vérification sur la confirmation du mot de passe.
    bool confirmation_mdp_valide = mdp == confirmation_mdp;

    // On récupère le nom d'utilisateur saisi.
    std::string nom_utilisateur = ui->saisie_user->toPlainText().toStdString();
    // On fait la vérification du nom d'utilisateur.
    bool nom_utilisateur_valide = nom_utilisateur.length() >= 2;

    // On teste si un paramètre saisi est invalide.
    if (!mail_valide || !mdp_valide || !confirmation_mdp_valide || !nom_utilisateur_valide) {
        // Si c'est invalide on affiche un message d'erreur.
        std::cout << "Il y a un problème !\n";
        fflush(stdout);
    } else {
        // Si tout est valide, on affiche les informations saisies dans le terminal
        // et on ferme la fenêtre de dialogue.
        this->accept(); // On ferme le dialogue.
    }
}

// En cas d'appui sur annuler.
void Inscription::on_validation_rejected()
{
    this->reject(); // On ferme la fenêtre de dialogue.
}

// Procédure permettant de récupérer les informations rentrée par l'utilisateur.
//
// adresse_mail un pointeur contenant l'adresse vers le string de l'adresse mail donnée
// nom_utilisateur un pointeur contenant l'adresse vers le string du nom d'utilisateur donné
// mot_de_passe un pointeur contenant l'adresse vers le string du mot de passe donné
void Inscription::getDonnees(std::string& adresse_mail, std::string& nom_utilisateur, std::string& mot_de_passe)
{
    adresse_mail = ui->saisie_mail->toPlainText().toStdString();
    nom_utilisateur = ui->saisie_user->toPlainText().toStdString();
    mot_de_passe = ui->saisie_mdp->toPlainText().toStdString();
}
