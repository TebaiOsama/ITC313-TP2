#include "Commande.h"

int main(){
	
	std::vector<Produit> produits_commandes;
	produits_commandes.push_back(Produit("Television", 600));
	produits_commandes.push_back(Produit("PS4", 300));
	Client Premier(1,"Marc","Antoine");
	Commande commande(Premier,produits_commandes,true);

	std::cout<<commande;
	return 0;
}