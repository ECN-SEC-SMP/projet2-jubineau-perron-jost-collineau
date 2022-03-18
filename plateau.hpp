#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
    bool victoire = false; //indique la victoire d'un joueur et permet d'arréter le jeu (false par default)
    vector<Case> cases; //contient les case du plateau
		Pioche pioche; //la pioche du plateau
    vector<Joueur*> joueurs; //contient les joueurs du plateau

		Tortue *tortueBleue = new Tortue(bleu);
		Tortue *tortueVerte = new Tortue(vert);
		Tortue *tortueRouge = new Tortue(rouge);
		Tortue *tortueJaune = new Tortue(jaune);
		Tortue *tortueViolette = new Tortue(violet);

	public :
	  Plateau(int nbJoueurs = 5);
		void ajouterJoueur(Joueur * monJoueur); 
		void Jeu();
		void deplacerTortue(Carte maCarte);
    Tortue* getTortue(Couleur c);
    string toString();
    friend std::ostream& operator<< (ostream &, Plateau &c);
    
};

//--------------------------
//Constructeur
//--------------------------
Plateau::Plateau(int nbJoueurs){
	//init cases
  for (int i=0; i<10; i++){
		Case newCase(i);
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

void Plateau::Jeu(){
	int carteChoisie = -1; 
	Symbole symboleCarteChoisie;
	Couleur couleurCartechoisie;
  vector<Tortue> tortuesADeplacees;

  while(!victoire){
    int i = 0;	
    while( ((++i)<joueurs.size()) && (!victoire) ){
      cout << endl << endl << endl; //espaces pour la lisibilitee
      //cout << "\u001b[1J"; //ou clear screen (choisir entre les deux)
      cout << *this << endl; //Afficher le plateau
  		joueurs[i]->afficher_info_joueur();
      
  		carteChoisie = joueurs[i]->choisirCarte();
  		symboleCarteChoisie = joueurs[i]->getCardSymbole(carteChoisie);
  		couleurCartechoisie = joueurs[i]->getCardCouleur(carteChoisie);
  		this->deplacerTortue(*(joueurs[i]->getCard(carteChoisie)));
  		joueurs[i]->defausserCarte(carteChoisie);
  	}
  }
}

void Plateau::deplacerTortue(Carte maCarte){
	
	int posTortue = -1;
	Couleur coul = maCarte.getCouleur();
	Symbole symb = maCarte.getSymbole();
	Tortue* current;

  //si multicolor et pas f ou ff
	//acquisition tortue a jouer
	if ( (coul == multicolor) && !((symb == f) || (symb == ff)) ){
		char tortueChoisie;
		cout << "Quelle tortue jouer ? " << endl;
		cout << "Bleue (B), Verte (G) , Rouge (R),Jaune (J), Violet (P)" << endl;
		while (true){
			cin >>  tortueChoisie;;
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
	        current = getTortue(bleu);
	        break;
			case 'V': 
	      current = getTortue(vert);
	      break;
			case 'R': 
	      current = getTortue(rouge);
	      break;
			case 'J': 
	      current = getTortue(jaune);
				break;
			case 'P': 
	      current = getTortue(violet);
	      break;
		}
	} else if( (symb == f) || (symb == ff) ){
    //trouver la dernière tortue dans le plateau
    //et prendre sa couleur
    bool done = false;
    int i = 0;
    while(!done){
      if(cases[i].getListeTortues().size() != 0){
        cout << "Tortue " << *(cases[i].getListeTortues()[0]) << "sélectionnée" << endl;
        coul = cases[i].getListeTortues()[0]->getCouleur();
        done = true;
      }
      i++;
    }
	} else {
		current = getTortue(coul);
  }

//Acquisition de la pos de la tortue
	int pos = current->getPosition();

	int deplacement = 0;
  switch(symb){
    case pp:
      deplacement = 2;
      break;
    case p:
			deplacement = 1;
      break;
    case m:
      deplacement = -1;
      break;
    case ff:
			deplacement = 2;
      break;
    case f:
			deplacement = 1;
      break;
	}
  //Gerer depassement superieur
  if( (pos+deplacement) > 10){
      deplacement = 1;
  }
  //Gerer depassement inferieur
  if( (pos+deplacement) < 0){
    deplacement = 0;
  }
  
	//Check gagnant - A COMPLETER SI PLUSIEURS TORTUES
	if ( (pos + deplacement) >= 10) {
		cout << "ON A UN GAGNANT !"	<< endl;
    //On arrete la boucle de jeu
    this->victoire = true; 
	}	

  //si déplacement à faire,
  //ajouter les tortues dans la nvlle case
  //et les supprimer de l'ancienne
  if(deplacement != 0){
    cases[pos+deplacement].addTortues(cases[pos].getListeTortuesFrom(current));
  	cases[pos].removeTortues(cases[pos].getListeTortuesFrom(current));
  }
}

//Entrée une couleur de tortue
//Retourne l'addresse de la tortue correspondante
Tortue* Plateau::getTortue(Couleur c){
  Tortue* ret = NULL;
  switch(c) {	//couleur
    case bleu:
      ret = tortueBleue;
			break;
		case vert: 
			ret = tortueVerte;
			break;
		case rouge:
			ret = tortueRouge;
			break;
		case jaune:
			ret = tortueJaune;
			break;
		case violet:
			ret = tortueViolette;
			break;
    default:
      break;
	}
  return ret;
}

string Plateau::toString(){
	string s = "------- PLATEAU -------";
	s += "\n";
	for (int i=0; i<10; i++){
		s+= cases[i].toString();
		//s += "\n";
	}
	return s;
}

std::ostream& operator<< (ostream &os, Plateau &c){
  os << c.toString();
  return os;
}
