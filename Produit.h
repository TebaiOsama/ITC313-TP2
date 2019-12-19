/** 
  * File:     Produit.cpp 
  * Author:   O.Tebai (Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Declaration of the class Produit
  */

#ifndef _produit_h
#define _produit_h

#include <string>

class Produit{
private:
	int m_id_produit;
	std::string m_titre_produit;
	std::string m_description_produit;
	int m_quantite_disponible;
	double m_prix_produit;
public:
	Produit(int t_id_produit, std::string t_titre_produit, double t_prix_produit, std::string t_description_produit="", int t_quantite_disponible=0);
	//getters
	int getIdProduit() const;
	std::string getTitreProduit() const;
	std::string getDescriptionProduit() const;
	int getQuantiteDisponible() const;
	double getPrixProduit() const;
	//setters
	void setQuantiteDisponible(int t_quantite_disponible);
	void setTitreProduit(std::string t_titre_produit);
	void setDescriptionProduit(std::string t_description_produit);
	void setPrixProduit(double t_prix_produit);
	//methodes
};

#endif