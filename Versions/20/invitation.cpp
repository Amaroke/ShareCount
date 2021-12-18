/* invitation.cpp
 * version 8
 * H. Iopeti, univ. Lorraine
 */

#include "invitation.hpp"

// Constructeur de la classe Inscription.
Invitation::Invitation(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Invitation)
    , compte("")
{
    ui->setupUi(this);
}

// Constructeur de la classe Invitation.
//
// QWidget parent
// Compte le compte
Invitation::Invitation(QWidget* parent, const std::string compte, const GestionnaireDialogue& gd)
    : QDialog(parent)
    , ui(new Ui::Invitation)
    , gestionnaire(gd)
    , compte(compte)
{
    ui->setupUi(this);
}
// Destructeur de la classe Inscription.
Invitation::~Invitation()
{
    delete ui;
}

// La fonction associée à un clic de bouton retour.
void Invitation::on_Retour_clicked()
{
    this->reject(); // On ferme la fenêtre de dialogue.
}

// La fonction associée à un clic de bouton valider.
void Invitation::on_valider_clicked()
{
    // On récupère l'email saisi.
    std::string mail = ui->mail->toPlainText().toStdString();
    // On fait les vérifications sur l'email (syntaxe correcte).
    // On teste si l'utilisateur saisi un paramètre et si la saisie est invalide.
    // Si le test est valide, on vérifie si l'utilisateur existe déjà à l'aide de son mail
    Utilisateur utilisateur = gestionnaire.getGestionnaireBDD().recherche_utilisateur(mail.c_str());
    //Pour passer un char* en string, il faut utiliser .c_str
    if (std::strcmp(utilisateur.get_adresse_mail().c_str(), "") != 0) {
        //On ajoute l'utilisateur à l'aide de son mail, si
        gestionnaire.getGestionnaireBDD().ajouter_utilisateur_compte(utilisateur.get_adresse_mail(), compte);
    } else {
        // Si le test est invalide, on affiche un message d'erreur sur la sortie standard.
        std::cout << "Veuillez recommencer !\n";
    }
    fflush(stdout);
    this->accept();
}
