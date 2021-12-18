---------- ShareCount ----------

Projet de CPOA | 08/12/2021
Hugo Iopeti & Hugo Mathieu Steinbach & Ludovic Yvoz

-----------------------------

Démarrage

Liste des comptes crées par défaut : 

	Mail(s) | Mot de passe(s)
	
	henriette@orange.fr | 05121990
	claude@sfr.fr | JeSuisClaude54
	cunégonde@free.fr | 88McGyver
	patrocle@gmail.com | Troie
	octavie@orange.fr | CésarLeJeune
	jeannic@sfr.fr | Dofus4life


A Savoir : 

	Supprimer le dossier de build supprime le fichier contenant la base de données ce qui entraîne la perte des données sauvegardées lors de cette session.

	Il faut supprimer le build/la base de données entre chaque lancement de version contenant la base de données.

Doxygen : 
	
    Documentation déjà présente :
    
        Le fichier Doxyfile contient la configuration de notre documentation.

        Le fichier Documentation.pdf contient la documentation déjà générée de la dernière version de notre application (version 23).

	Construire la documentation : 
   
        - Copiez le fichier Doxyfile dans le dossier contenant la version du code que vous voulez documenter.

        - Ouvrez un terminal dans ce dossier.

        - Tapez les comandes suivantes :
            $doxygen Doxyfile
            $cd latex
            $make

        - La documentation est maintenant générée sous forme de pdf, pour la récupérer il suffit d'aller chercher dans le dossier latex venant d'être créé le fichier nommé refman.pdf.
	
	
Fonctionnalitées de la version finale :
	
	-> Historique de versions.

-----------------------------
