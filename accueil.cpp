#include "accueil.hpp"

// Le constructeur de la classe.
Accueil::Accueil(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Accueil)
    , gestionnaire_dialogue()
{
    ui->setupUi(this);
}

// Le destructeur de la classe.
Accueil::~Accueil() { delete ui; }

// Fonction qui connecte un utilisateur à l'application en fonction de l'adresse mail et du mot de passe donné en paramètre.
//
// adresse_mail l'adresse mail donnée
// mot_de_passe un pointeur contenant le mot de passe donné
// mdp_correct un pointeur vers un booléen qui indique si le mot de passe est correct
//
// Retourne un booléen qui indique si l'utilisateur s'est connecté.
bool Accueil::connexion_utilisateur(const std::string& adresse_mail,
    const std::string& mot_de_passe,
    bool& mdp_correct)
{
    Utilisateur utilisateur = gestionnaire_dialogue.recherche_utilisateur(adresse_mail);
    bool utilisateur_existe = true;
    mdp_correct = false;
    if (utilisateur.get_adresse_mail() != "" || utilisateur.get_mot_de_passe() != "" || utilisateur.get_nom_utilisateur() != "") {
        if (utilisateur.get_mot_de_passe() == mot_de_passe) {
            mdp_correct = true;
        }
    } else {
        utilisateur_existe = false;
    }

    return utilisateur_existe;
}

// Création d'une fenêtre de d'inscription depuis la mainwindows.
void Accueil::fenetre_creer_un_compte()
{
    Inscription* inscription = new Inscription(this); // On instancie la classe Inscription.
    inscription->setWindowTitle("Créer un compte"); // On nomme la fenêtre.
    inscription->exec(); // On affiche la fenêtre de dialogue, tant qu'elle n'est pas fermée, on attend.
    if (inscription->result() == QDialog::Accepted) {
        std::string adresse_mail;
        std::string nom_utilisateur;
        std::string mot_de_passe;
        inscription->getDonnees(adresse_mail, nom_utilisateur, mot_de_passe); //On récupère les données rentrées par l'utilisateur dans la fenêtre
        Utilisateur nouvel_utilisateur = Utilisateur(nom_utilisateur, adresse_mail, mot_de_passe);
        bool mdp_correct;
        bool utilisateur_existe_vraiment = this->connexion_utilisateur(adresse_mail, mot_de_passe, mdp_correct);
        if (utilisateur_existe_vraiment) {
            //MESSAGE D'ERREUR DU STYLE COMPTE EXISTE DEJA
            this->fenetre_se_connecter(adresse_mail, mot_de_passe);
        } else {
            gestionnaire_dialogue.ajouter_utilisateur(nouvel_utilisateur);
            gestionnaire_dialogue.set_utilisateur_connecte(nouvel_utilisateur);
            (new FenetreUtilisateur(nullptr,gestionnaire_dialogue))->show();
            this->close();
        }
    }
}

// Création d'une fenêtre de connexion depuis la mainwindows.
//
// adresse_mail l'adresse mail donnée
// mot_de_passe un pointeur contenant le mot de passe donné
// utilisateur_existe un booléen qui contient l'information de l'existence du compte
void Accueil::fenetre_se_connecter(const std::string& adresse_mail, const std::string& mot_de_passe, const bool utilisateur_existe)
{
    Connexion* connexion;
    if (adresse_mail == "" && mot_de_passe == "" && utilisateur_existe == false) {
        connexion = new Connexion(this); // On instancie la classe Connexion.
    } else {
        connexion = new Connexion(this, adresse_mail, mot_de_passe, utilisateur_existe); // On instancie la classe Connexion avec les données et le message d'erreur correspondant.
    }
    connexion->setWindowTitle("Se connecter"); // On nomme la fenêtre.
    connexion->exec(); // On affiche la fenêtre de dialogue, tant qu'elle n'est pas fermée, on attends.
    if (connexion->result() == QDialog::Accepted) {
        std::string mail;
        std::string mdp;
        connexion->getDonnees(mail, mdp); //On récupère les données rentrées par l'utilisateur dans la fenêtre
        bool mdp_correct;
        bool utilisateur_existe_vraiment = this->connexion_utilisateur(mail, mdp, mdp_correct);
        if (utilisateur_existe_vraiment && mdp_correct) {
            gestionnaire_dialogue.set_utilisateur_connecte(gestionnaire_dialogue.recherche_utilisateur(mail));
            (new FenetreUtilisateur(nullptr, gestionnaire_dialogue))->show();
            this->close();
        } else {
            if (utilisateur_existe_vraiment && !mdp_correct) {
                //MESSAGE D'ERREUR MDP
            } else {
                //MESSAGE D'ERREUR ADRESSE MAIL CORRESPOND PAS A COMPTE
            }
            fenetre_se_connecter(mail, mdp, utilisateur_existe_vraiment);
        }
    }
}

// La fonction associée à un clic de bouton de création de compte.
void Accueil::on_creer_compte_clicked() { fenetre_creer_un_compte(); }

// La fonction associée à un clic de bouton sur se connecter.
void Accueil::on_se_connecter_clicked() { fenetre_se_connecter(); }

// La fonction associée à un clic de bouton sur afficher l'utilisateur connecté.
void Accueil::on_afficher_connecter_clicked()
{
    std::cout
        << gestionnaire_dialogue.get_utilisateur_connecte().get_adresse_mail() << "\n";
    std::cout
        << gestionnaire_dialogue.get_utilisateur_connecte().get_mot_de_passe() << "\n";
    std::cout
        << gestionnaire_dialogue.get_utilisateur_connecte().get_nom_utilisateur() << "\n";
    fflush(stdout);
}

// La fonction associée à un clic de bouton sur quitter l'application. @version 6 @author H. Mathieu Steinbach, univ. Lorraine
void Accueil::on_quitter_appli_clicked()
{
    this->close();
}
