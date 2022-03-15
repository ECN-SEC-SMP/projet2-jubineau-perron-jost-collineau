#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

#include "case.hpp"
#include "pioche.hpp"
#include "joueur.hpp"
#include "typeDef.hpp"

using namespace std;

//------------------------------------------------------------------------------
// @class Plateau
// 
//------------------------------------------------------------------------------

class Plateau
{
  private:
    vector<Case> cases;
		Pioche pioche;
    vector<Joueur*> joueurs;

		Tortue *tortueBleue = new Tortue(Couleur bleu);
		Tortue *tortueVerte = new Tortue(Couleur vert);
		Tortue *tortueRouge = new Tortue(Couleur rouge);
		Tortue *tortueJaune = new Tortue(Couleur jaune);
		Tortue *tortueViolette = new Tortue(Couleur violet);

	public :
	  Plateau(int nbJoueurs);
		void ajouterJoueur(Joueur * monJoueur); 
		void tourDeJeu();
    //string toString();
    //friend std::ostream& operator<< (ostream &, Carte &);
};

//--------------------------
//Constructeur
//--------------------------
Carte::Plateau(int nbJoueurs = 5){
	//init cases
  for (int i=0; i++; i<10){
		Case newCase(i)
		cases.push_back(newCase);
	}
	//init tortues
	cases[0].addTortue(tortueBleue);
	cases[0].addTortue(tortueVerte);
	cases[0].addTortue(tortueRouge);
	cases[0].addTortue(tortueJaune);
	cases[0].addTortue(tortueViolette);

	
}

//--------------------------
//Méthodes diverses
//--------------------------
void Plateau::ajouterJoueur(Joueur * monJoueur){
	joueurs.push_back(monJoueur);
} 


void Plateau::tourDeJeu(){
	
	for (int i=0; i++; i<joueurs.size()){
		joueurs[i].afficher_info_joueur();
	}
	cout << "Quelle carte jouer ?"	<< endl;
	
	int carteChoisie -1; 
	Symbole symboleCarteChoisie;
	Couleur couleurCartechoisie;
	
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
	symboleCarteChoisie = joueurs[i].getCardSymbole(carteChoisie);
	couleurCartechoisie = joueurs[i].getCardCouleur(carteChoisie);

	joueurs[i].defausserCarte(carteChoisie);
	//TODO APPEL DEPLACER TORTUE
	
}

/*
string Carte::toString(){
	
}

std::ostream& operator<< (ostream &os, Carte &c){
  os << c.toString();
  return os;
}
*/