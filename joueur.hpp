#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 

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
    bool is_IA = false;

  public :
    Joueur();
    Joueur(string name, Couleur couleur_tortue, bool IA);

    void afficher_info_joueur();

		void jouerCarte(int nbr);
    void piocher_1_carte(Pioche pile_de_cartes);
		void piocher_5_cartes(Pioche pile_de_cartes);
		void defausserCarte(int nbr);
    int choisirCarte();
    Couleur choisirCouleur();

    void setCouleur(Couleur couleur_tortue);

    Couleur getCouleur(void);
		Carte *getCard(int nbr);
		Couleur getCardCouleur(int nbr);
		Symbole getCardSymbole(int nbr);

    string couleur_to_string();
    friend ostream& operator<< (ostream &, Joueur &j);
};

//--------------------------
//Constructeurs
//--------------------------

Joueur::Joueur(){
	this->nom = "unnamed";
}

Joueur::Joueur(string name, Couleur couleur_tortue, bool IA)
{
  this->nom = name;   //on set le nom du joueur avec celui donné en paramètre
  this->couleur = couleur_tortue;

  this->is_IA = IA;
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

Carte *Joueur::getCard(int nbr){
	return this->cartes_en_main[nbr];
}

Couleur Joueur::getCardCouleur(int nbr){
	return this->cartes_en_main[nbr]->getCouleur();
}

Symbole Joueur::getCardSymbole(int nbr){
	return this->cartes_en_main[nbr]->getSymbole();
}


//--------------------------
//Méthodes diverses
//--------------------------

int Joueur::choisirCarte(){
  int carteChoisie;
  if(this->is_IA == true)
  {
    cout << "L'IA choisie une carte :"	<< endl;
    carteChoisie = rand()%5;
    cout << carteChoisie << endl;
  }
  else {
    cout << "Quelle carte jouer ?"	<< endl;
  	while (true){
    	cin >> carteChoisie;
    	if (cin.fail()) {
    	  cin.clear(); cin.ignore();
    	  cout << "Entree invalide, reesayer :" << endl;
    	}
    	else if(carteChoisie < 0 || 5 < carteChoisie) {
    		cin.clear(); cin.ignore();
    		cout << "Entree invalide, reesayer :"<< endl;
  		}
    	else break;
    }
  }
  return carteChoisie;
}

//Choisir une couleur parmis les 5
Couleur Joueur::choisirCouleur(void){
  Couleur coul;
  if(is_IA){
    cout << "L'IA choisie une couleur :"	<< endl;
    coul = static_cast<Couleur>(rand() % 5);
    cout << coul << endl;
  } 
  else{
    char tortueChoisie;
		cout << "Quelle tortue jouer ? " << endl;
		cout << "Bleue (B), Verte (G) , Rouge (R),Jaune (J), Violet (P)" << endl;
		while (true){
			cin >>  tortueChoisie;
			string testStr = "BGRJP";
			if (cin.fail()) {
	      cin.clear(); cin.ignore();
	      cout << "Entree invalide, reesayer :" << endl;
	    } 
			else if ( testStr.find(tortueChoisie) != std::string::npos) {
				break;
			} 
			else 
				cin.clear(); cin.ignore();
				cout << "Entree invalide, reesayer :"<< endl;
		}
		switch (tortueChoisie) {
	    case 'B': 
        coul = bleu;
        break;
			case 'G': 
	      coul = vert;
	      break;
			case 'R': 
	      coul = rouge;
	      break;
			case 'J': 
	      coul = jaune;
				break;
			case 'P': 
	      coul = violet;
	      break;
		}
  }
  return coul;
}

//permet de jouer une carte et la supprime de la main du joueur
void Joueur::defausserCarte(int nbr)
{  
  if ((nbr > 4) || (0 > nbr)) return;
	else {
		cartes_en_main.erase(cartes_en_main.begin()+(nbr));
	}
}

void Joueur::piocher_1_carte(Pioche pile_de_cartes){
  cartes_en_main.push_back(pile_de_cartes.piocher());
}

// Permet au joueur en début de partie de piocher 5 cartes 
void Joueur::piocher_5_cartes(Pioche pile_de_cartes)
{
  for(int i = 0; i<5; i++)
  {
    cartes_en_main.push_back(pile_de_cartes.piocher());
  }
}

// Retourne la couleur de la tortue associée au joueur sous forme de string
string Joueur::couleur_to_string(){
	string string_couleur;
  
	switch (this->couleur)  {	//couleur
    case bleu: 
			string_couleur = "bleu";
			break;
		case vert: 
			string_couleur = "vert";
			break;
		case rouge:
			string_couleur = "rouge";
			break;
		case jaune:
			string_couleur = "jaune";
			break;
		case violet:
			string_couleur = "violet";
			break;
    case multicolor:
      string_couleur = "multicolor";
    break;
	}
	return string_couleur;
}

// Affiche à l'écran toutes les informations sur le Joueur
void Joueur::afficher_info_joueur()
{
  cout << " --- INFO JOUEUR --- " << endl;
  
  cout << "Nom = " << this->nom;
  if(this->is_IA == true)
    cout << " - IA";
  cout << endl;
  
  cout << "Tortue = " << couleur_to_string() << endl;
  cout << " Cartes en main :" << endl;
  for(int i=0 ; i < cartes_en_main.size() ; i++){
    cout << " n°" << i << " : " << cartes_en_main[i]->toString() << endl;
  }
  cout << " ---             --- " << endl;
}

std::ostream& operator<< (ostream &os, Joueur &j){
  os << j.nom;
  return os;
}