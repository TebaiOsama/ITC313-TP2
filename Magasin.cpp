/** 
  * File:     Magasin.cpp 
  * Author:   F.Forrer/O.Tebai (Francois_Forrer@etu.u-bourgogne.fr/Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Definition of the class Magasin
  */

#include "Magasin.h"


Magasin::Magasin(){}

Magasin::Magasin(std::vector<Produit*> t_produits){
	m_produits = t_produits;
}
/*
Magasin::Magasin(std::vector<Produit*> t_produits, std::vector<Client*> t_clients, std::vector<Commande*> t_commandes){
	m_produits = t_produits;
	m_commandes = t_commandes;
	m_clients = t_clients;
}
*/
void Magasin::ajoutProduit(std::string t_titre_produit, double t_prix_produit, int t_quantite_disponible, std::string t_description_produit){
	m_produits.push_back(new Produit(t_titre_produit, t_prix_produit, t_quantite_disponible, t_description_produit));
}

void Magasin::affichageProduits(){
	std::cout<<"Produits disponibles : "<<std::endl<<std::endl;
	std::cout<<"Nom\t\t\tDescription\t\t\tQuantite\tPrix"<<std::endl;
	for(int i=0; (unsigned)i<m_produits.size(); i++){
		std::cout<<m_produits[i]->getTitreProduit();
		m_produits[i]->tabulations(m_produits[i]->getTitreProduit().length(), true);
		std::cout<<m_produits[i]->getDescriptionProduit();
		m_produits[i]->tabulations(m_produits[i]->getDescriptionProduit().length(), false);
		std::cout<<m_produits[i]->getQuantiteDisponible()
				 <<"\t\t"
				 <<m_produits[i]->getPrixProduit()<<"€"<<std::endl;
	}
	std::cout<<std::endl;
}

void Magasin::affichageProduitParNom(std::string t_nom_produit){
	std::cout<<"Details du produit : "<<std::endl<<std::endl;
	for(int i=0; (unsigned)i<m_produits.size(); i++){
		if(m_produits[i]->getTitreProduit()==t_nom_produit){
			std::cout<<m_produits[i]->getTitreProduit();
			m_produits[i]->tabulations(m_produits[i]->getTitreProduit().length(), true);
			std::cout<<m_produits[i]->getDescriptionProduit();
			m_produits[i]->tabulations(m_produits[i]->getDescriptionProduit().length(), false);
			std::cout<<m_produits[i]->getQuantiteDisponible()
				     <<"\t\t"
				     <<m_produits[i]->getPrixProduit()<<"€"<<std::endl;
		}
	}
	std::cout<<std::endl;
}

void Magasin::majQuantiteProduit(std::string t_nom_produit, int t_quantite_produit){
	for(int i=0; (unsigned)i<m_produits.size(); i++){
		if(m_produits[i]->getTitreProduit()==t_nom_produit){
			m_produits[i]->setQuantiteDisponible(t_quantite_produit);
			break;
		}
	}
}

void Magasin::ajoutClient(std::string t_nom_client, std::string t_prenom_client){
	int id;
	if(m_clients.size()==0)
		id=1;
	else
		id=m_clients[m_clients.size()-1]->getIdClient()+1;
	
	m_clients.push_back(new Client(id,t_nom_client, t_prenom_client));
}

void Magasin::affichageClients(){
	std::cout<<"Clients : "<<std::endl<<std::endl
			 <<"ID\t\tIdentité"<<std::endl;
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		std::cout<<m_clients[i]->getIdClient()
				 <<"\t\t"
				 <<m_clients[i]->getNomClient()
				 <<" "
				 <<m_clients[i]->getPrenomClient()
				 <<std::endl;
	}	
	std::cout<<std::endl;
}

void Magasin::affichageClientParNom(std::string t_nom_client, std::string t_prenom_client){
	std::cout<<"Details du client : "<<std::endl<<std::endl;
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getNomClient()==t_nom_client && m_clients[i]->getPrenomClient()==t_prenom_client){
			std::cout<<m_clients[i]->getIdClient()
					 <<"\t\t"
					 <<m_clients[i]->getNomClient()
					 <<" "
					 <<m_clients[i]->getPrenomClient()
					 <<std::endl;
		}
	}	
	std::cout<<std::endl;
}

void Magasin::affichageClientParNom(int t_id_client){
	std::cout<<"Details du client : "<<std::endl<<std::endl;
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getIdClient()==t_id_client){
			std::cout<<m_clients[i]->getIdClient()
					 <<"\t\t"
					 <<m_clients[i]->getNomClient()
					 <<" "
					 <<m_clients[i]->getPrenomClient()
					 <<std::endl;
		}
	}	
	std::cout<<std::endl;
}

void Magasin::ajoutProduitPanierClient(std::string t_nom_client, std::string t_prenom_client, std::string t_nom_produit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){	//on va essayer de trouver le client pour mettre le produit dans son panier
		if(m_clients[i]->getNomClient()==t_nom_client && m_clients[i]->getPrenomClient()==t_prenom_client){
			for(int j=0; (unsigned)j<m_produits.size(); j++){ //si on trouve le client, on cherche le produit dans le magasin
				if(m_produits[j]->getTitreProduit()==t_nom_produit){
					if(m_produits[j]->getQuantiteDisponible()>0){//on verifie si la quantite disponible est non nulle
						m_clients[i]->addProduit(*m_produits[j]);
						m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()-1);
						break;
					}
					else
						std::cout<<"Le produit n'est plus disponible"<<std::endl;
				}
			}
		}
	}
}

void Magasin::ajoutProduitPanierClient(int t_id_client, std::string t_nom_produit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getIdClient()==t_id_client){
			for(int j=0; (unsigned)j<m_produits.size(); j++){ //si on trouve le client, on cherche le produit dans le magasin
				if(m_produits[j]->getTitreProduit()==t_nom_produit){
					if(m_produits[j]->getQuantiteDisponible()>0){//on verifie si la quantite disponible est non nulle
						m_clients[i]->addProduit(*m_produits[j]);
						m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()-1);
						break;
					}
					else
						std::cout<<"Le produit n'est plus disponible"<<std::endl;
				}
			}
		}
	}
}

void Magasin::effacerProduitPanierClient(std::string t_nom_client, std::string t_prenom_client, std::string t_nom_produit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){	//on va essayer de trouver le client pour mettre le produit dans son panier
		if(m_clients[i]->getNomClient()==t_nom_client && m_clients[i]->getPrenomClient()==t_prenom_client){
			for(int j=0; (unsigned)j<m_produits.size(); j++){ //si on trouve le client, on cherche le produit dans le magasin
				if(m_produits[j]->getTitreProduit()==t_nom_produit){ //si on trouve le produit, on l'efface et on ajoute tous les produits qu'on vient d'effacer dans le magasin
					m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()+m_clients[i]->getQuantiteObjet(t_nom_produit));
					m_clients[i]->supprimerProduit(t_nom_produit);

				}
			}
		}
	}
}

void Magasin::effacerProduitPanierClient(int t_id_client, std::string t_nom_produit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getIdClient()==t_id_client){
			for(int j=0; (unsigned)j<m_produits.size(); j++){ //si on trouve le client, on cherche le produit dans le magasin
				if(m_produits[j]->getTitreProduit()==t_nom_produit){ //si on trouve le produit, on l'efface
					m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()+m_clients[i]->getQuantiteObjet(t_nom_produit));
					m_clients[i]->supprimerProduit(t_nom_produit);
				}
			}
		}
	}
}

void Magasin::setProduitPanierClient(std::string t_nom_client, std::string t_prenom_client, std::string t_nom_produit, int t_quantite_produit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){	//on va essayer de trouver le client pour mettre le produit dans son panier
		if(m_clients[i]->getNomClient()==t_nom_client && m_clients[i]->getPrenomClient()==t_prenom_client){
			for(int j=0; (unsigned)j<m_produits.size(); j++){ //si on trouve le client, on cherche le produit dans le magasin
				if(m_produits[j]->getTitreProduit()==t_nom_produit){ //si on trouve le produit, 
					m_clients[i]->modifQuantiteObjet(t_nom_produit, t_quantite_produit);
					m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()-t_quantite_produit);
					std::cout<<"La quantitée du produit "<<t_nom_produit<<" a été correctement modifiée !"<<std::endl;
				}
			}
		}
	}
}

void Magasin::setProduitPanierClient(int t_id_client, std::string t_nom_produit, int t_quantite_produit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getIdClient()==t_id_client){
			for(int j=0; (unsigned)j<m_produits.size(); j++){ //si on trouve le client, on cherche le produit dans le magasin
				if(m_produits[j]->getTitreProduit()==t_nom_produit){ //si on trouve le produit, 
					m_clients[i]->modifQuantiteObjet(t_nom_produit, t_quantite_produit);
					m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()-t_quantite_produit);
					std::cout<<"La quantitée du produit "<<t_nom_produit<<" a été correctement modifiée !"<<std::endl;
				}
			}
		}
	}
}

void Magasin::ajoutCommande(Client t_client, std::vector<Produit> t_produits_commandes, bool t_status){
	m_commandes.push_back(new Commande(t_client, t_produits_commandes, t_status));
}

void Magasin::validerCommande(Commande t_commande){
	std::string valid;
	//std::cout<<m_commandes[m_commandes.size()-1]<<std::endl; // afficher la commande si ce n'est pas fait
	std::cout<<"Voulez vous valider la commande ? (O ou N) "<<std::endl;
	std::cin>>valid;
	if(valid=="o" || valid=="O"){
		std::cout<<"Commande validée"<<std::endl;
		m_commandes.push_back(new Commande(t_commande.getClient(), t_commande.getProduitsCommandes(), t_commande.getStatus()));
	}
	else if(valid=="n" || valid=="N")
		std::cout<<"Commande annulée"<<std::endl;
}

void Magasin::majStatusCommande(bool t_status, Commande t_commande){
	t_commande.setStatus(t_status);
}

void Magasin::afficherCommandes(){
	if(m_commandes.size()==0){
		std::cout<<"Il n'y a pas de commande";
	}
	std::cout<<"Il y a "<<m_commandes.size()<<" commandes :"<<std::endl;
	for (int i = 0; (unsigned)i < m_commandes.size(); i++){
		std::cout<<*m_commandes[i]<<std::endl;
	}
}

void Magasin::afficherCommandesClient(int m_id_client){
	int a=0;
	if(m_commandes.size()==0){
		std::cout<<"Ce client n'a pas de commande";
	}
	else{ 
		for (int i = 0; (unsigned)i < m_commandes.size(); i++){
			if(m_clients[i]->getIdClient()==m_id_client)
			std::cout<<*m_commandes[i]<<std::endl;
			else
				a++; // Compteur pour vérifier si il y a des commandes affichées
		}
		if((unsigned)a==m_commandes.size())
			std::cout<<"Ce client n'a pas de commande"<<std::endl;
	}
}

