#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gestionnaire_dialogue()
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

bool MainWindow::connexion_utilisateur(std::string adresse_mail,
                                       std::string mot_de_passe)
{
    Utilisateur utilisateur = gestionnaire_dialogue.recherche_utilisateur(adresse_mail, mot_de_passe);
    bool utilisateur_existe = true;

    if (utilisateur.get_id() != -1) {
        gestionnaire_dialogue.set_utilisateur_connecte(utilisateur);
    } else {
        utilisateur_existe = false;
    }

    return utilisateur_existe;
}

void MainWindow::fenetre_creer_un_compte()
{
    Inscription* inscription = new Inscription(this); // On instancie la classe Inscription.
    inscription->setWindowTitle("Créer un compte"); // On nomme la fenêtre.
    inscription->show(); // On affiche la fenêtre de dialogue.
}

void MainWindow::fenetre_se_connecter()
{
    Connexion* connexion = new Connexion(this); // On instancie la classe Connexion.
    connexion->setWindowTitle("Se connecter"); // On nomme la fenêtre.
    connexion->show(); // On affiche la fenêtre de dialogue.
}

void MainWindow::on_creer_compte_clicked() { fenetre_creer_un_compte(); }

void MainWindow::on_se_connecter_clicked() { fenetre_se_connecter(); }

void MainWindow::on_afficher_connecter_clicked()
{
    std::cout
            << gestionnaire_dialogue.get_utilisateur_connecte().get_adresse_mail() << "\n";
    std::cout << gestionnaire_dialogue.get_utilisateur_connecte().get_id() << "\n";
    std::cout
            << gestionnaire_dialogue.get_utilisateur_connecte().get_mot_de_passe() << "\n";
    std::cout
            << gestionnaire_dialogue.get_utilisateur_connecte().get_nom_utilisateur() << "\n";
    fflush(stdout);
}
