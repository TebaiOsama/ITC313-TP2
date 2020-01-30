#include "header.h"

bool VerificationNumerique(){
	if(!std::cin){ //si l'utilisateur n'entre pas un nombre
	    std::cin.clear(); // on reset cin
	    std::cin.ignore(256, '\n'); //on saute les input faux
    	std::cout<<"Entrez une valeur numerique : ";
		return false;
	}	
	return true;
}

void demarrer(){
	int reponse1;
	std::cout<<"TP2 CPP : EASYSTORE"<<std::endl;
	std::cin.ignore();
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

void gestionMagasin(){
	std::cout<<"Vous avez choisi gestion du magasin."<<std::endl;
	
}

void gestionUtilisateurs(){}

void gestionCommandes(){}

void quitter(){
	system("clear");
	std::cout<<"Merci pour avoir choisi notre Easystore ! "<<std::endl;
}