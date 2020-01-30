#include "Menu.h"

Menu::Menu(){
	std::cout<<"TP2 CPP : EASYSTORE (appuyez sur une touche pour continuer)"<<std::endl;
	std::cin.ignore();
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
	system("clear");

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

void Menu::gestionUtilisateurs(){
	std::string reponse="";
	int reponse2;
	std::string prenom, nom;
	std::cout<<"Vous avez choisi gestion des utilisateurs."<<std::endl;
	int n_utilisateurs = m_liste_utilisateurs.size();
	switch(n_utilisateurs){
		case 0: std::cout<<"Il n'a aucun utilisateur, voulez vous en créer un ? (O/N)"<<std::endl;
		
		while(reponse!="O" && reponse!="o" && reponse!="N" && reponse!="n"){
			std::cin>>reponse;
			if(reponse=="O" || reponse=="o"){
				std::cout<<"Entrez le nom, puis le prenom de l'utilisateur : "<<std::endl;
				std::cin>>nom;
				std::cin>>prenom;
				m_liste_utilisateurs.push_back(Client(1,nom,prenom));
				m_iterateur = 0;
				std::cout<<"Votre nouveau client a été correctement créé ! "<<std::endl;
			}
			else if(reponse=="N" || reponse=="n"){
				std::cout<<"Retour au menu principale... (appuyez sur une touche pour continuer)"<<std::endl;
				std::cin.ignore();
				demarrer();
			}
			else{
				std::cout<<"Veuillez entrer O ou N : "<<std::endl;
			}
		}
		break;

		case 1: std::cout<<"Vous avez un seul client, est-ce que vous voulez choisir celui ci ou en créer un autre ? (1/2)"<<std::endl;

		while(reponse!="1" && reponse!="2"){
			std::cin>>reponse;
			if(reponse=="1"){
				m_iterateur = 0;
			}
			else if(reponse=="2"){
				std::cout<<"Entrez le nom, puis le prenom de l'utilisateur : "<<std::endl;
				std::cin>>nom;
				std::cin>>prenom;
				m_liste_utilisateurs.push_back(Client(2,nom,prenom));
				m_iterateur = 1;
				std::cout<<"Votre nouveau client a été correctement créé ! "<<std::endl;
			}
			else{
				std::cout<<"Veuillez entrer 1 ou 2 : "<<std::endl;
			}
		}

		break;

		default: std::cout<<"Vous avez "<<n_utilisateurs<<" magasins. Est-ce que vous voulez en choisir un parmi ceux la ou en créer un autre ? (1/2)"<<std::endl;

		while(reponse!="1" && reponse!="2"){
			std::cin>>reponse;
			if(reponse=="1"){
				std::cout<<"Entrez quel ID utilisateur vous souhaitez gérer : "<<std::endl;
				std::cin>>reponse2;
				while(!VerificationNumerique()){
					std::cin>>reponse2;
				}
				while(reponse2>n_utilisateurs || reponse2<1){
					std::cout<<"Choisissez une valeur entre 1 et "<<n_utilisateurs<<" : "<<std::endl;
					std::cin>>reponse2;
				}
				m_iterateur = n_utilisateurs;
			}
			else if(reponse=="2"){
				std::cout<<"Entrez le nom, puis le prenom de l'utilisateur : "<<std::endl;
				std::cin>>nom;
				std::cin>>prenom;
				m_liste_utilisateurs.push_back(Client(m_liste_utilisateurs.size(),nom,prenom));
				m_iterateur = m_liste_utilisateurs.size()-1;
			}
			else{
				std::cout<<"Veuillez entrer 1 ou 2 : "<<std::endl;
			}
		}
		break;
	}
	commandeUtilisateurs();
}

void Menu::commandeUtilisateurs(){
	system("clear");
	int reponse2;
	std::cout<<"Choisissez l'action à faire : "<<std::endl
			 <<"1. Ajouter un produit"<<std::endl
			 <<"2. Vider la liste des produits"<<std::endl
			 <<"3. Modifier la quantité d'un objet"<<std::endl
			 <<"4. Supprimer un produit"<<std::endl
			 <<"5. Retour au menu principale"<<std::endl;

	std::cin>>reponse2;

	while(!VerificationNumerique()){
		std::cin>>reponse2;
	}
	while(reponse2>5 || reponse2<1){
		std::cout<<"Choisissez une valeur entre 1 et 5 : "<<std::endl;
		std::cin>>reponse2;
	}
	system("clear");
	switch(reponse2){
		case 1:
		{
			std::string titre_produit, description_produit;
			double prix_produit;
			int quantite_produit;
			std::cout<<"Vous avez choisi de ajouter un nouveau produit au panier"<<std::endl;
			std::cout<<"Entrez le titre du produit : "<<std::endl;
			std::cin>>titre_produit;
			std::cout<<"Entrez le prix du produit : "<<std::endl;
			std::cin>>prix_produit;
			while(!VerificationNumerique()){
				std::cin>>prix_produit;
			}
			std::cout<<"Entrez combien vous en voulez : "<<std::endl;
			std::cin>>quantite_produit;
			while(!VerificationNumerique()){
				std::cin>>quantite_produit;
			}
			std::cout<<"Entrez une petite description du produit : "<<std::endl;
			std::cin>>description_produit;
			m_liste_utilisateurs[m_iterateur].addProduit(Produit(titre_produit, prix_produit, quantite_produit, description_produit));

			break;
		}
		case 2:
		std::cout<<"Vous avez choisi de vider la liste des produits"<<std::endl;
		m_liste_utilisateurs[m_iterateur].viderListeProduits();
		break;

		case 3:
		{
			std::string nom_produit;
			int quantite_produit;
			std::cout<<"Vous avez choisi de modifier la quantité d'un objet"<<std::endl
					 <<"Entrez le nom du produit : "<<std::endl;
			std::cin>>nom_produit;
			std::cout<<"Entrez la quantité : "<<std::endl;
			std::cin>>quantite_produit;
			while(!VerificationNumerique()){
				std::cin>>quantite_produit;
			}
			m_liste_utilisateurs[m_iterateur].modifQuantiteObjet(nom_produit, quantite_produit);
			break;
		}
		case 4:
		{
			std::string nom_produit;
			std::cout<<"Vous avez choisi de supprimer un produit"<<std::endl
					 <<"Entrez le nom du produit: "<<std::endl;
			std::cin>>nom_produit;

			m_liste_utilisateurs[m_iterateur].supprimerProduit(nom_produit);
			break;
		}
		case 5:
		demarrer();
		break;
	}
	
	commandeUtilisateurs();

}

void Menu::gestionMagasin(){
	std::cout<<"Vous avez choisi gestion du magasin."<<std::endl;
	// int n_utilisateurs;
	// switch(n_utilisateurs){
	// 	case 0
	// }
}

void Menu::gestionCommandes(){}

void Menu::quitter(){
	system("clear");
	std::cout<<"Merci pour avoir choisi notre Easystore ! "<<std::endl;
	exit(0);
}