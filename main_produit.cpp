/** 
  * File:     main_produit.cpp 
  * Author:   O.Tebai (Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Testing of class Produit
  */

#include <iostream>
#include "Produit.h"

std::ostream& operator<<(std::ostream& t_flux, Produit& t_produit){
	t_flux<<"Titre Produit : "<<t_produit.getTitreProduit()<<std::endl
	  	  <<"Description Produit : "<<t_produit.getDescriptionProduit()<<std::endl
		  <<"Quantite Disponible : "<<t_produit.getQuantiteDisponible()<<std::endl
		  <<"Prix Produit : "<<t_produit.getPrixProduit()<<std::endl;
	return t_flux;
}

int main(){
	Produit Switch("Nintendo",54);
	std::cout<<Switch;
}