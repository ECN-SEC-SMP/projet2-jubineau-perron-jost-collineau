#pragma once
#include <iostream>
#include <vector>

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

		setPosition(int newPos);
    int getPosition();

    deplacerTortue(int nbrCases);
}

//--------------------------
//Constructeur
//--------------------------
void Tortue::Tortue(Couleur maCouleur)
{
  this->couleur = maCouleur;
	this->position = 0;
}

//--------------------------
//Getteurs et Setteurs
//--------------------------
void tortue::setPosition(int newPos){
	this->position = newPos;
}

int tortue::getPosition(){
	return (this->position);
}

//--------------------------
//Méthodes diverses
//--------------------------

void tortue::deplacerTortue(int nbrCases)
{
  
}