/**
  * File:     Menu.cpp
  * Authors:  O.Tebai/F.Forrer (Osama_Tebai@etu.u-bourgogne.fr/Francois_Forrer@etu.u-bourgogne.fr)
  * Date:     2020
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique
  * Summary:  Definition of the class Menu
  */

#include "Menu.h"

Menu::Menu(){
	std::cout<<"TP2 CPP : EASYSTORE (appuyez sur la touche ENTER pour continuer)"<<std::endl;
	std::cin.ignore();

	//lecture du fichier

	std::ifstream fichier;
	fichier.open ("save.txt");
	if(fichier){
		std::string ligne; //Une variable pour stocker les lignes lues
		while(getline(fichier,ligne)){
			if(ligne == "Produits:"){	//On passe la première ligne pour ne pas prendre en compte "Produit:"
				getline(fichier,ligne);
			}
			while(ligne != "Clients:"){ 	//S'assurer qu'il s'agit des produits
				
				std::string titre_produit, description_produit;
				double prix_produit;
				int quantite_produit;

				titre_produit=ligne;					
				getline(fichier,ligne);

				prix_produit=stof(ligne);							
				getline(fichier,ligne);

				quantite_produit=stoi(ligne);						
				getline(fichier,ligne);

				description_produit=ligne;					
				getline(fichier,ligne);
				easystore.ajoutProduit(titre_produit, prix_produit, quantite_produit, description_produit);

			}
			int i=1;
			std::string nom, prenom;
			if(ligne == "Clients:"){	//On passe la première ligne pour ne pas prendre en compte "Client:"
				getline(fichier,ligne);
			}
			while(ligne != "Commandes:"){		//On s'assure qu'il s'agit des clients
				

				if(stoi(ligne) == i){			//on passe à chaque fois l'id qui s'écrira automatiquement
					getline(fichier,ligne);
				}

				nom=ligne;
				getline(fichier,ligne);

				prenom=ligne;
				getline(fichier,ligne);

				easystore.ajoutClient(nom, prenom);
				i++;
			}

			if(ligne == "Commandes:"){	//On passe la première ligne pour ne pas prendre en compte "Commandes:"
				std::cout<<ligne <<std::endl;
				getline(fichier,ligne);
			}
			//mettre les composantes des commandes
		}
	}
}

bool Menu::VerificationNumerique(){
	if(!std::cin){ //si l'utilisateur n'entre pas un nombre
	    std::cin.clear(); // on reset cin
	    std::cin.ignore(256, '\n'); //on saute les input faux
    	std::cout<<"Entrez une valeur numerique : ";
		return false;
	}	
	return true;
}

void Menu::demarrer(){

	int reponse1;
	system("clear");
	std::cout<<"Choisissez l'action à faire : "<<std::endl<<std::endl
			 <<"1. Gestion du magasin"<<std::endl
			 <<"2. Gestion des utilisateurs"<<std::endl
			 <<"3. Gestion des commandes"<<std::endl
			 <<"4. Quitter"<<std::endl;
	std::cin>>reponse1;
	while(!VerificationNumerique()){
		std::cin>>reponse1;
	}
	while(reponse1>4 || reponse1<1){
		std::cout<<"Choisissez une valeur entre 1 et 4 : "<<std::endl;
		std::cin>>reponse1;
	}
	// system("clear");

	switch(reponse1){
		case 1: gestionMagasin();
		break;
		case 2: gestionUtilisateurs();
		break;
		case 3: gestionCommandes();
		break;
		case 4: quitter();
		break;
	}
}

void Menu::gestionMagasin(){
	// system("clear");
	int reponse;
	std::cout<<std::endl<<"Vous avez choisi gestion du magasin."<<std::endl
			 <<"Choisissez l'action à faire : "<<std::endl
			 <<"1. Ajouter un produit "<<std::endl
			 <<"2. Afficher tous les produits"<<std::endl
			 <<"3. Afficher les produits avec le meme nom"<<std::endl
			 <<"4. Modifier la quantité d'un produit"<<std::endl
			 <<"5. Retour au menu principale"<<std::endl;;
	std::cin>>reponse;
	while(!VerificationNumerique()){
		std::cin>>reponse;
	}
	while(reponse>5 || reponse<1){
		std::cout<<"Entrez une valeur entre 1 et 5 : "<<std::endl;
		std::cin>>reponse;
	}

	switch(reponse){
		case 1: 
		{
		std::string titre_produit, description_produit;
		double prix_produit;
		int quantite_produit;
		std::cout<<"Vous avez choisi d'ajouter un produit au magasin."<<std::endl;

		std::cout<<"Entrez le titre du produit : "<<std::endl;
		std::cin>>titre_produit;
		std::cout<<"Entrez le prix du produit : "<<std::endl;
		std::cin>>prix_produit;
		while(!VerificationNumerique()){
			std::cin>>prix_produit;
		}
		std::cout<<"Entrez combien il y en a : "<<std::endl;
		std::cin>>quantite_produit;
		while(!VerificationNumerique()){
			std::cin>>quantite_produit;
		}
		std::cout<<"Entrez une petite description du produit : "<<std::endl;
		std::cin>>description_produit;
		easystore.ajoutProduit(titre_produit, prix_produit, quantite_produit, description_produit);
		
		gestionMagasin();
		break;

		}
		case 2:
		std::cout<<"Vous avez chosi de afficher tous les produits."<<std::endl;
		if(easystore.getListeProduits().size()==0)
			std::cout<<"La liste des produits est vide."<<std::endl;
		else
			easystore.affichageProduits();

		gestionMagasin();
		break;

		case 3:
		{
		std::cout<<"Vous avez chosi de afficher tous les produits avec le meme nom."<<std::endl;
		std::string nom_produit;
		std::cout<<"Entrez le nom du produit que vous souhaitez voir : "<<std::endl;
		std::cin>>nom_produit;
		easystore.affichageProduitParNom(nom_produit);

		gestionMagasin();
		break;
		}

		case 4:
		{
		std::cout<<"Vous avez choisi de changer la quantité disponible d'un produit."<<std::endl;
		
		std::string nom_produit;
		int quantite_produit;

		std::cout<<"Entrez le nom du produit dont vous souhaitez modifier la quantité : "<<std::endl;
		std::cin>>nom_produit;

		std::cout<<"Entrez la nouvelle quantité : "<<std::endl;
		std::cin>>quantite_produit;
		while(!VerificationNumerique()){
			std::cin>>quantite_produit;
		}
		easystore.majQuantiteProduit(nom_produit, quantite_produit);

		gestionMagasin();
		break;
		}

		case 5:
		demarrer();
		quitter();
	}
}

void Menu::gestionUtilisateurs(){
	// system("clear");
	int reponse;
	std::cout<<std::endl<<"Vous avez choisi gestion des utilisateurs."<<std::endl
			 <<"Choisissez l'action à faire : "<<std::endl
			 <<"1. Ajouter un client "<<std::endl
			 <<"2. Afficher tous les clients"<<std::endl
			 <<"3. Afficher des clients specifiques"<<std::endl
			 <<"4. Ajouter un produit au panier"<<std::endl
			 <<"5. Effacer un produit du panier"<<std::endl
			 <<"6. Modifier la quantité de produits dans le panier"<<std::endl
			 <<"7. Retour au menu principale"<<std::endl;
	std::cin>>reponse;
	while(!VerificationNumerique()){
		std::cin>>reponse;
	}
	while(reponse>7 || reponse<1){
		std::cout<<"Entrez une valeur entre 1 et 7 : "<<std::endl;
		std::cin>>reponse;
	}

	switch(reponse){
		case 1: 
		{
		std::cout<<"Vous avez choisi d'ajouter un client."<<std::endl;
		std::string nom, prenom;
		std::cout<<"Entrez le nom, puis le prenom : "<<std::endl;
		std::cin>>nom;
		std::cin>>prenom;

		easystore.ajoutClient(nom, prenom);

		gestionUtilisateurs();
		break;
		}
		case 2:
		std::cout<<"Vous avez chosi d'afficher tous le clients."<<std::endl;
		easystore.affichageClients();

		gestionUtilisateurs();
		break;

		case 3:
		{
		std::cout<<"Vous avez choisi d'afficher des clients specifiques."<<std::endl;
		std::cout<<"Vous voulez afficher les clients par ID ou par nom et prenom ? (1/2)"<<std::endl;
		std::cin>>reponse;
		while(!VerificationNumerique()){
			std::cin>>reponse;
		}
		while(reponse>2 && reponse<1){
			std::cout<<"Entrez une valeur entre 1 et 2 : "<<std::endl;
			std::cin>>reponse;
		}
		if(reponse==1){
			int id;
			std::cout<<"Entrez l'ID client : "<<std::endl;
			std::cin>>id;
			while(!VerificationNumerique()){
				std::cin>>reponse;
			}
			easystore.affichageClientParNom(id);
		}
		else{
			std::string nom, prenom;
			std::cout<<"Entrez le nom puis le prenom du client :"<<std::endl;
			std::cin>>nom;
			std::cin>>prenom;

			easystore.affichageClientParNom(nom, prenom);
		}

		gestionUtilisateurs();
		break;

		}
		case 4: 
		{
			std::cout<<"Vous avez choisi d'ajouter un produit au panier d'un client"<<std::endl;
			std::cout<<"Vous voulez choisir le clients par ID ou par nom et prenom ? (1/2)"<<std::endl;
			std::cin>>reponse;
			std::string nom_produit;
			while(!VerificationNumerique()){
				std::cin>>reponse;
			}
			while(reponse>2 && reponse<1){
				std::cout<<"Entrez une valeur entre 1 et 2 : "<<std::endl;
				std::cin>>reponse;
			}
			if(reponse==1){
				int id, erreur=0, quantite;
				std::cout<<"Entrez l'ID client : "<<std::endl;

				//s'assurer que le client existe
				std::cin>>id;
				while(!VerificationNumerique()){
					std::cin>>reponse;
				}


				std::cout<<"Entrez le nom du produit que vous souhaitez ajouter au panier du client :"<<std::endl;
				
				while(erreur==0){
					std::cin>>nom_produit;
					for(int i=0; (unsigned)i<easystore.getListeProduits().size(); i++){
						if(easystore.getListeProduits()[i]->getTitreProduit()==nom_produit){
							erreur++;
						}
					}
					if(erreur==0){ //si le produit est inexistant
						std::cout<<"Le produit saisi est inexistant, veuillez entrer à nouveau le nom ou quitter (1/2)"<<std::endl;
						std::cin>>reponse;
						while(!VerificationNumerique()){
							std::cin>>reponse;
						}
						if(reponse==2)
							gestionUtilisateurs();
					}
				}
				
				std::cout<<"Vous en voulez combien ?"<<std::endl;
				std::cin>>quantite;
				while(!VerificationNumerique()){
					std::cin>>reponse;
				}

				easystore.ajoutProduitPanierClient(id, nom_produit, quantite);
			}
			else{
				std::string nom, prenom;
				int erreur=0, quantite;
				std::cout<<"Entrez le nom puis le prenom du client :"<<std::endl;
				std::cin>>nom;
				std::cin>>prenom;

				std::cout<<"Entrez le nom du produit que vous souhaitez ajouter au panier du client :"<<std::endl;
				
				while(erreur==0){
					std::cin>>nom_produit;
					for(int i=0; (unsigned)i<easystore.getListeProduits().size(); i++){
						if(easystore.getListeProduits()[i]->getTitreProduit()==nom_produit){
							erreur++;
						}
					}
					if(erreur==0){ //si le produit est inexistant
						std::cout<<"Le produit saisi est inexistant, veuillez entrer à nouveau le nom ou quitter (1/2)"<<std::endl;
						std::cin>>reponse;
						while(!VerificationNumerique()){
							std::cin>>reponse;
						}
						if(reponse==2)
							gestionUtilisateurs();
					}
				}

				std::cout<<"Vous en voulez combien ?"<<std::endl;
				std::cin>>quantite;
				while(!VerificationNumerique()){
					std::cin>>reponse;
				}

				easystore.ajoutProduitPanierClient(nom, prenom, nom_produit, quantite);
			}

		
		gestionUtilisateurs();
		break;
		}

		case 5:
		{
			std::cout<<"Vous avez choisi de supprimer un produit du panier"<<std::endl;
			std::cout<<"Vous voulez choisir le clients par ID ou par nom et prenom ? (1/2)"<<std::endl;
			std::cin>>reponse;
			std::string nom_produit;
			while(!VerificationNumerique()){
				std::cin>>reponse;
			}
			while(reponse>2 && reponse<1){
				std::cout<<"Entrez une valeur entre 1 et 2 : "<<std::endl;
				std::cin>>reponse;
			}
			if(reponse==1){
				int id;
				std::cout<<"Entrez l'ID client : "<<std::endl;

				//s'assurer que le client existe
				std::cin>>id;
				while(!VerificationNumerique()){
					std::cin>>reponse;
				}

				std::cout<<"Entrez le nom du produit que vous souhaitez supprimer du panier du client :"<<std::endl;
				std::cin>>nom_produit;
				
				

				easystore.effacerProduitPanierClient(id, nom_produit);
			}
			else{
				std::string nom, prenom;
				
				std::cout<<"Entrez le nom puis le prenom du client :"<<std::endl;
				std::cin>>nom;
				std::cin>>prenom;

				std::cout<<"Entrez le nom du produit que vous souhaitez supprimer du panier du client :"<<std::endl;
				std::cin>>nom_produit;
				

				easystore.effacerProduitPanierClient(nom, prenom, nom_produit);
			}


		gestionUtilisateurs();
		break;
		}

		case 6: 
		{
			std::cout<<"Vous avez choisi de modifier la quantité d'un produit dans le panier"<<std::endl;
			std::cout<<"Vous voulez choisir le clients par ID ou par nom et prenom ? (1/2)"<<std::endl;
			std::cin>>reponse;
			std::string nom_produit;
			while(!VerificationNumerique()){
				std::cin>>reponse;
			}
			while(reponse>2 && reponse<1){
				std::cout<<"Entrez une valeur entre 1 et 2 : "<<std::endl;
				std::cin>>reponse;
			}
			if(reponse==1){
				int id, quantite;
				std::cout<<"Entrez l'ID client : "<<std::endl;

				//s'assurer que le client existe
				std::cin>>id;
				while(!VerificationNumerique()){
					std::cin>>reponse;
				}


				std::cout<<"Entrez le nom du produit que vous souhaitez modifier  :"<<std::endl;
				std::cin>>nom_produit;
				
				std::cout<<"Entrez la quantité souhaitée :"<<std::endl;
				std::cin>>quantite;
				easystore.setProduitPanierClient(id, nom_produit, quantite);
			}
			else{
				std::string nom, prenom;
				int quantite;
				std::cout<<"Entrez le nom puis le prenom du client :"<<std::endl;
				std::cin>>nom;
				std::cin>>prenom;

				std::cout<<"Entrez le nom du produit que vous souhaitez modifier :"<<std::endl;
				std::cin>>nom_produit;
				
				std::cout<<"Entrez la quantité souhaitée :"<<std::endl;
				std::cin>>quantite;
				easystore.setProduitPanierClient(nom, prenom, nom_produit, quantite);
			}

		
		gestionUtilisateurs();
		break;
		}

		case 7:
		demarrer();
		break;
	}

}

void Menu::gestionCommandes(){
	// system("clear");
	int reponse;
	std::cout<<std::endl<<"Vous avez choisi gestion des commandes."<<std::endl
			 <<"Choisissez l'action à faire : "<<std::endl
			 <<"1. Afficher toutes les commandes"<<std::endl
			 <<"2. Afficher des commandes specifiques à un client"<<std::endl
			 <<"3. Mettre à jour le status d'une commande"<<std::endl
			 <<"4. Valider une commande"<<std::endl
			 <<"5. Retour au menu principale"<<std::endl;
	std::cin>>reponse;
	while(!VerificationNumerique()){
		std::cin>>reponse;
	}
	while(reponse>5 || reponse<1){
		std::cout<<"Entrez une valeur entre 1 et 5 : "<<std::endl;
		std::cin>>reponse;
	}

	switch(reponse){

		case 1:
			std::cout<<"Vous avez choisi d'afficher toutes les commandes."<<std::endl;
			if(easystore.getListeCommandes().size()==0)
				std::cout<<"La liste des commandes est vide."<<std::endl;
			else
				easystore.afficherCommandes();

			gestionCommandes();
			break;

		case 2:
		{
			int id;
			std::string nom, prenom;
			std::cout<<"Vous avez choisi d'afficher toutes les commandes specifiques d'un client"<<std::endl;
			std::cout<<"Vous voulez afficher les commandes des clients par ID ou par nom et prenom ? (1/2)"<<std::endl;
			std::cin>>reponse;
			while(!VerificationNumerique()){
				std::cin>>reponse;
			}
			while(reponse>2 && reponse<1){
				std::cout<<"Entrez une valeur entre 1 et 2 : "<<std::endl;
				std::cin>>reponse;
			}	

			if(reponse==1){
				std::cout<<"Entrez l'ID du client :"<<std::endl;
				std::cin>>id;
				while(!VerificationNumerique()){
					std::cin>>id;
				}
				easystore.afficherCommandesClient(id);
			}
			else{
				std::cout<<"Entrez nom, puis prenom du client : "<<std::endl;
				std::cin>>nom;
				std::cin>>prenom;

				easystore.afficherCommandesClient(nom, prenom);
			}

			gestionCommandes();
			break;

		}

		case 3:
		{
			int iterateur, id;
			std::string nom, prenom;
			std::cout<<"Vous avez choisi de mettre à jour le status d'une commande."<<std::endl;
			std::cout<<"Vous voulez choisir le client par ID ou par nom et prenom ? (1/2)"<<std::endl;
			std::cin>>reponse;
			while(!VerificationNumerique()){
				std::cin>>reponse;
			}
			while(reponse>2 && reponse<1){
				std::cout<<"Entrez une valeur entre 1 et 2 : "<<std::endl;
				std::cin>>reponse;
			}	

			if(reponse==1){
				std::cout<<"Entrez l'ID du client :"<<std::endl;
				std::cin>>id;
				while(!VerificationNumerique()){
					std::cin>>id;
				}
				for(int i=0; (unsigned)i<easystore.getListeCommandes().size();i++){
					if(easystore.getListeCommandes()[i]->getClient().getIdClient()==id)
						iterateur = i;
				}
			}
			else{
				std::cout<<"Entrez nom, puis prenom du client : "<<std::endl;
				std::cin>>nom;
				std::cin>>prenom;

				for(int i=0; (unsigned)i<easystore.getListeCommandes().size();i++){
					if(easystore.getListeCommandes()[i]->getClient().getNomClient()==nom && easystore.getListeCommandes()[i]->getClient().getPrenomClient()==prenom)
						iterateur = i;
				}
			}

			std::cout<<"Entrez le status que vous souhaitez imposer (0 = false /1 = true): "<<std::endl;
			std::cin>>reponse;
			while(!VerificationNumerique()){
				std::cin>>id;
			}
			while(reponse>1 && reponse<0){
				std::cout<<"Entrez une valeur entre 0 et 1 : "<<std::endl;
				std::cin>>reponse;
			}

			easystore.majStatusCommande(reponse==0?false:true,*easystore.getListeCommandes()[iterateur]);

			gestionCommandes();
			break;
		}

		case 4:
		{
			int id, iterateur;
			std::string nom, prenom;
			std::cout<<"Vous avez choisi de valider une commande"<<std::endl;
			std::cout<<"Vous voulez choisir le client par ID ou par nom et prenom ? (1/2)"<<std::endl;
			std::cin>>reponse;
			while(!VerificationNumerique()){
				std::cin>>reponse;
			}
			while(reponse>2 && reponse<1){
				std::cout<<"Entrez une valeur entre 1 et 2 : "<<std::endl;
				std::cin>>reponse;
			}	

			if(reponse==1){
				std::cout<<"Entrez l'ID du client :"<<std::endl;
				std::cin>>id;
				while(!VerificationNumerique()){
					std::cin>>id;
				}

				for(int i=0; (unsigned)i<easystore.getListeCommandes().size();i++){
					if(easystore.getListeCommandes()[i]->getClient().getIdClient()==id)
						iterateur = i;
				}
			}
			else{
				std::cout<<"Entrez nom, puis prenom du client : "<<std::endl;
				std::cin>>nom;
				std::cin>>prenom;

				for(int i=0; (unsigned)i<easystore.getListeCommandes().size();i++){
					if(easystore.getListeCommandes()[i]->getClient().getNomClient()==nom && easystore.getListeCommandes()[i]->getClient().getPrenomClient()==prenom)
						iterateur = i;
				}
			}

			easystore.ajoutCommande(*easystore.getListeClients()[iterateur], easystore.getListeClients()[iterateur]->getListeProduits(), false);
			easystore.validerCommande(*easystore.getListeCommandes()[iterateur]);
			easystore.getListeClients()[iterateur]->viderListeProduits();
			gestionCommandes();
			break;

		}
		case 5:
			demarrer();
			break;
	}
}

void Menu::quitter(){
	system("clear");

	std::ofstream fichier;
	fichier.open ("save.txt");
	fichier << "Produits:\n" ;
	for(int i=0; (unsigned)i<easystore.getListeProduits().size();i++){
		fichier << easystore.getListeProduits()[i]->getTitreProduit()<<std::endl
				<< easystore.getListeProduits()[i]->getPrixProduit()<<std::endl
				<< easystore.getListeProduits()[i]->getQuantiteDisponible()<<std::endl
				<< easystore.getListeProduits()[i]->getDescriptionProduit()<<std::endl;
	}

	fichier << "Clients:\n" ;
	for(int i=0; (unsigned)i<easystore.getListeClients().size();i++){
		fichier << easystore.getListeClients()[i]->getIdClient()<<std::endl
				<< easystore.getListeClients()[i]->getNomClient()<<std::endl
				<< easystore.getListeClients()[i]->getPrenomClient()<<std::endl;
	}

	fichier << "Commandes:\n" ;
	for(int i=0; (unsigned)i<easystore.getListeCommandes().size();i++){
		fichier << easystore.getListeCommandes()[i]->getClient().getIdClient()<<std::endl;
		for(int j=0; (unsigned)j<easystore.getListeCommandes()[i]->getProduitsCommandes().size(); i++){
			fichier << easystore.getListeCommandes()[i]->getProduitsCommandes()[j].getTitreProduit()<<std::endl
					<< easystore.getListeCommandes()[i]->getProduitsCommandes()[j].getPrixProduit()<<std::endl
					<< easystore.getListeCommandes()[i]->getProduitsCommandes()[j].getQuantiteDisponible()<<std::endl
					<< easystore.getListeCommandes()[i]->getProduitsCommandes()[j].getDescriptionProduit()<<std::endl;
		}
	}
	
	fichier.close();
	std::cout<<"Merci pour avoir choisi notre Easystore ! "<<std::endl;
	exit(0);
}
