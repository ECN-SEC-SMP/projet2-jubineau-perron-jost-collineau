#pragma once
#include <stdio.h>
#include <string.h>

#include "typeDef.hpp"

using namespace std;

class Carte
{
  private:
    Symbole symbole;
		Couleur couleur;
  
	public :
	  Carte(Symbole monSymbole, Couleur maCouleur);

		Symbole getSymbole();
		Couleur getCouleur();

    string toString();
    friend std::ostream& operator<< (ostream &, Carte &);
};

Carte::Carte(Symbole monSymbole, Couleur maCouleur){
  symbole = monSymbole;
	couleur = maCouleur;
}

Symbole Carte::getSymbole(){
	return this->symbole;
}

Couleur Carte::getCouleur(){
	return this->couleur;
}

string Carte::toString(){
	string s = "Carte ";
	switch (this->symbole)  {	//symbole
		case p :
			s+= "+1 ";
			break;
		case pp :
			s+= "+2 ";
			break;
		case m:
			s+= "+1 ";
			break;
		case mm:
			s+= "-2 ";
			break;
		case f:
			s+= "fleche +1 ";
			break;
		case ff:
			s+= "fleche +2 ";
			break;
	}
	switch (this->couleur)  {	//couleur
    case bleu: 
			s+= "bleue ";
			break;
		case vert: 
			s+= "verte ";
			break;
		case rouge:
			s+= "rouge ";
			break;
		case jaune:
			s+= "jaune ";
			break;
		case violet:
			s+= "violette ";
			break;
	  case multicolor:
			s+= "multicolore ";
			break;
	}
	return s;
}

std::ostream& operator<< (ostream &os, Carte &c){
  os << c.toString();
  return os;
}