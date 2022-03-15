#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>

#include "carte.hpp"
#include "pioche.hpp"
#include "typeDef.hpp"

using namespace std;


//------------------------------------------------------------------------------
// @class Joueur
// La classe Joueur permet d'abstraire un joueur physique à un objet dans 
// notre programme. 
//------------------------------------------------------------------------------

class Joueur
{
  private :
    string nom;
    Couleur couleur;
    vector<Carte*> cartes_en_main;

  public :
    Joueur();
    Joueur(string name, Couleur couleur_tortue);

    void afficher_info_joueur();
    string couleur_to_string();
		void jouerCarte(int nbr);

    void setCouleur(Couleur couleur_tortue);
    Couleur getCouleur(void);
		Couleur getCardCouleur(int nbr)
		Symbole getCardSymbole(int nbr)
};

//--------------------------
//Constructeurs
//--------------------------

Joueur::Joueur(){
	this->nom = "unnamed";
}

Joueur::Joueur(string name, Couleur couleur_tortue)
{
  this->nom = name;   //on set le nom du joueur avec celui donné en paramètre
  this->couleur = couleur_tortue;
}

//--------------------------
//Getteurs et Setteurs
//--------------------------
void Joueur::setCouleur(Couleur couleur_tortue)
{
  this->couleur = couleur_tortue;
}

Couleur Joueur::getCouleur(void)
{
  return this->couleur;
}

Couleur Joueur::getCardCouleur(int nbr){
	return this->cartes_en_main[nbr].getCouleur();
}

Symbole Joueur::getCardSymbole(int nbr){
	return this->cartes_en_main[nbr].getSymbole();
}


//--------------------------
//Méthodes diverses
//--------------------------

//permet de jouer une carte et la supprime du deck du joueur
void Joueur::defausserCarte(int nbr)
{
  if (nbr > cartes_en_main.size() || cartes_en_main.size > nbr ) return;
	else {
		cartes_en_main.erase(nbr);
	}
}


// Permet au joueur en début de partie de piocher 5 cartes 
void Joueur::piocher_5_cartes(Pioche pile_de_cartes)
{
  for(int i = 0; i<5; i++)
  {
    cartes_en_main.push_back(pile_de_cartes -> piocher())
  }
}

// Retourne la couleur de la tortue associée au joueur sous forme de string
string Joueur::couleur_to_string(){
	string string_couleur;
  
	switch (this->couleur)  {	//couleur
    case bleu: 
			string_couleur = "rouge";
			break;
		case vert: 
			string_couleur = "jaune";
			break;
		case rouge:
			string_couleur = "bleue";
			break;
		case jaune:
			string_couleur = "verte";
			break;
		case violet:
			string_couleur = "violette";
			break;
	}
	return string_couleur;
}

// Affiche à l'écran toutes les informations sur le Joueur
void Joueur::afficher_info_joueur()
{
  cout << " --- INFO JOUEUR --- " << endl;
  cout << "Nom = " << nom << endl;
  cout << "Tortue = " << couleur_to_string() << endl;
  cout << " Cartes en main :" << endl;
  for(int i=0 ; i < cartes_en_main.size() ; i++){
    cout << " n°" << i << " : " << cartes_en_main[i]->toString() << endl;
  }
  cout << " ---             --- " << endl;
}

