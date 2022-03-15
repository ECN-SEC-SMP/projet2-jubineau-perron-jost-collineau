#pragma once
#include <iostream>
#include <vector>
#include "case.hpp"
#include "typeDef.hpp"

using namespace std;

//------------------------------------------------------------------------------
// @class Case
// 
//------------------------------------------------------------------------------

class Case
{
  private:
    vector<Tortue*> listeTortues;
    int numero;

  public:
    Case(int num);
		void addTortue(Tortue maTortue);
    vector<Tortue> getListeTortues(void);
    }
};

//--------------------------
//Constructeur
//--------------------------
Case::Case(int num){
  this->numero = num;
}

//--------------------------
//Getteurs et Setteurs
//--------------------------
void Case::addTortue(Tortue maTortue){
	maTortue->setPosition(numero);
	listeTortues.push_back(maTortue);
}

Case::Case(int num){
  this->numero = num;
}

vector<Tortue> Case::getListeTortues(void){
  return listeTortues;
}