/** 
  * File:     Produit.cpp 
  * Author:   F.Forrer/O.Tebai (Francois_Forrer@etu.u-bourgogne.fr/Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Definition of the class Produit
  */


#include "Produit.h"


Produit::Produit(){}
Produit::Produit(std::string t_titre_produit, double t_prix_produit, int t_quantite_disponible, std::string t_description_produit){
	m_titre_produit = t_titre_produit;
	m_quantite_disponible = t_quantite_disponible;
	m_prix_produit = t_prix_produit;
	m_description_produit = t_description_produit;
}

//getters
std::string Produit::getTitreProduit() const{
	return m_titre_produit;
}
std::string Produit::getDescriptionProduit() const{
	return m_description_produit;
}
int Produit::getQuantiteDisponible() const{
	return m_quantite_disponible;
}
double Produit::getPrixProduit() const{
	return m_prix_produit;
}
//setters
void Produit::setQuantiteDisponible(int t_quantite_disponible){
	m_quantite_disponible = t_quantite_disponible;
}


//methodes
void Produit::tabulations(int t_longeur_mot, bool t_name){
	int tabs = t_longeur_mot/8;//une tabulation vaut 8 espaces
	int i=0;
	if(t_name)
		tabs=3-tabs; 
	else
		tabs=4-tabs; 

	while(i<tabs){
			std::cout<<"\t"; //on affiche le nombre de tabulations
			i++;
		}
}

//surcharge d'operateur
std::ostream& operator<<(std::ostream& t_flux, Produit& t_produit){
	t_flux<<"Titre Produit : "<<t_produit.getTitreProduit()<<std::endl
	  	  <<"Description Produit : "<<t_produit.getDescriptionProduit()<<std::endl
		  <<"Quantite Disponible : "<<t_produit.getQuantiteDisponible()<<std::endl
		  <<"Prix Produit : "<<t_produit.getPrixProduit()<<std::endl;
	return t_flux;
}