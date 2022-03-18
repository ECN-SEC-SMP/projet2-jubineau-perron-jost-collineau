#pragma once
#include <iostream>
#include <vector>

#include "typeDef.hpp"

using namespace std;

//------------------------------------------------------------------------------
// @class Tortue
// Classe qui défini les tortues présentes sur le plateau de jeu.
// Elles ont chacunes une couleur unique.
//------------------------------------------------------------------------------

class Tortue
{
  private:
    Couleur couleur;
		int position;

  public:
    Tortue(Couleur maCouleur);

		void setPosition(int newPos);
    int getPosition();
    Couleur getCouleur(void);
		string toString();
    void deplacerTortue(int nbrCases);
};

//--------------------------
//Constructeur
//--------------------------
Tortue::Tortue(Couleur maCouleur)
{
  this->couleur = maCouleur;
	this->position = 0;
}

//--------------------------
//Getteurs et Setteurs
//--------------------------
void Tortue::setPosition(int newPos){
	this->position = newPos;
}

int Tortue::getPosition(){
	return (this->position);
}

Couleur Tortue::getCouleur(void){
  return this->couleur;
}

//--------------------------
//Méthodes diverses
//--------------------------

void Tortue::deplacerTortue(int nbrCases)
{
  
}

string Tortue::toString(){
	string s = ""; //"Tortue ";
	switch(this->getCouleur())  {	//couleur
    case bleu:
			s+= "bleue";
			break;
		case vert: 
			s+= "verte";
			break;
		case rouge:
			s+= "rouge";
			break;
		case jaune:
			s+= "jaune";
			break;
		case violet:
			s+= "violette";
			break;
	  case multicolor:
			s+= "multicolor";
			break;
    default:
      s+= "ERREUR";
      break;
	}
	return s;
}

std::ostream& operator<< (ostream &os, Tortue &t){
  os << t.toString();
  return os;
}