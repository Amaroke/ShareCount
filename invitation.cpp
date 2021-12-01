/* invitation.cpp
 * version 8
 * H. Iopeti, univ. Lorraine
 */

#include "invitation.hpp"

// Constructeur de la classe Inscription.
Invitation::Invitation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Invitation),
    compte(CompteDepensesPartagees(Utilisateur("","",""),""))
{
    ui->setupUi(this);
}

// Constructeur de la classe Invitation.
//
// QWidget parent
// Compte le compte
Invitation::Invitation(QWidget* parent, const Compte& compte)
    : QDialog(parent)
    , ui(new Ui::Invitation),
    compte(compte)
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

// La fonction associée à un clic de bouton envoyer à nouveau.
void Invitation::on_envoyer_a_nouveau_clicked()
{

}

// La fonction associée à un clic de bouton valider.
void Invitation::on_valider_clicked()
{
    // On récupère l'email saisi.
    std::string mail = ui->mail->toPlainText().toStdString();

    // On fait les vérifications sur l'email (syntaxe correcte).
    const std::regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); // Regex pour la validité d'un mail.
    // On regarde si le pattern du mail match avec le mail saisi.
    bool mail_valide = std::regex_match(mail, pattern);
    Utilisateur utilisateur = Utilisateur("", "", "");

    // On teste si l'utilisateur saisi un paramètre et si la saisie est invalide.
    if (mail.length() > 0 && mail_valide) {
        // Si le test est valide, on vérifie si l'utilisateur existe déjà à l'aide de son mail
        Utilisateur utilisateur_recherche = gestionnaire.recherche_utilisateur(mail);
        //Pour passer un char* en string, il faut utiliser .c_str
        if(!std::strcmp(utilisateur_recherche.get_nom_utilisateur().c_str(),utilisateur.get_nom_utilisateur().c_str())){
            //On ajoute l'utilisateur à l'aide de son mail, si
            compte.ajouterUtilisateur(utilisateur_recherche);
        }
    } else {
        // Si le test est invalide, on affiche un message d'erreur sur la sortie standard.
        std::cout << "Veuillez recommencer !\n";
    }
    fflush(stdout);
}
