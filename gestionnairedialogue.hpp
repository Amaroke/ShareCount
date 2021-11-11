#ifndef GESTIONNAIREDIALOGUE_HPP
#define GESTIONNAIREDIALOGUE_HPP
#include "utilisateur.hpp"

class GestionnaireDialogue {
private:
    Utilisateur utilisateur_connecte;

public:
    GestionnaireDialogue();
    ~GestionnaireDialogue();
    Utilisateur get_utilisateur_connecte();
    void set_utilisateur_connecte(Utilisateur utilisateur);
    Utilisateur recherche_utilisateur(std::string adresse_mail,
                                      std::string mot_de_passe);
};

#endif // GESTIONNAIREDIALOGUE_HPP
