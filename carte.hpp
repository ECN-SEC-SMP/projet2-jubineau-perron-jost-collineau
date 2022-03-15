#pragma once
#include <stdio.h>
#include <string.h>

#include "typeDef.hpp"

using namespace std;

//------------------------------------------------------------------------------
// @class Carte
// 
//------------------------------------------------------------------------------

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

//--------------------------
//Constructeur
//--------------------------
Carte::Carte(Symbole monSymbole, Couleur maCouleur){
  symbole = monSymbole;
	couleur = maCouleur;
}

//--------------------------
//Getteurs et Setteurs
//--------------------------
Symbole Carte::getSymbole(){
	return this->symbole;
}

Couleur Carte::getCouleur(){
	return this->couleur;
}

//--------------------------
//Méthodes diverses
//--------------------------
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
			s+= "-1 ";
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
			s+= "\033[34mbleue\033[0m ";
			break;
		case vert: 
			s+= "\033[32mverte\033[0m ";
			break;
		case rouge:
			s+= "\033[31mrouge\033[0m ";
			break;
		case jaune:
			s+= "\033[33mjaune\033[0m ";
			break;
		case violet:
			s+= "\033[35mviolette\033[0m ";
			break;
	  case multicolor:
			s+= "\033[31mmu\033[32mlt\033[33mic\033[34mol\033[35more\033[0m ";
			break;
	}
	return s;
}

std::ostream& operator<< (ostream &os, Carte &c){
  os << c.toString();
  return os;
}