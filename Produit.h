/** 
  * File:     Produit.cpp 
  * Author:   O.Tebai (Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Declaration of the class Produit
  */

#ifndef _Produit_h
#define _Produit_h

#include <string>
#include <iostream>

class Produit{
private:
	std::string m_titre_produit;
	std::string m_description_produit;
	int m_quantite_disponible;
	double m_prix_produit;
public:
	Produit();
	Produit(std::string t_titre_produit, double t_prix_produit, int t_quantite_disponible=1, std::string t_description_produit="");
	//getters
	std::string getTitreProduit() const;
	std::string getDescriptionProduit() const;
	int getQuantiteDisponible() const;
	double getPrixProduit() const;
	//setters
	void setQuantiteDisponible(int t_quantite_disponible);

	//methodes
	void tabulations(int t_longeur_mot, bool t_name); //affiche le bon nombre de tabulations pour les deux methodes d'affichage
};

std::ostream& operator<<(std::ostream& t_flux, Produit& t_produit);

#endif