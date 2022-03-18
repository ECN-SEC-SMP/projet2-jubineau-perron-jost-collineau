#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "tortue.hpp"
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

//Fonctions de déplacement des tortues
//2versions possible : pour une ou plusieurs tortues
    void addTortue(Tortue* maTortue);
    void addTortues(vector<Tortue*> mesTortue);
    void removeTortue(Tortue* maTortue);
		void removeTortues(vector<Tortue*> mesTortue);

    vector<Tortue*> getListeTortues(void);
		vector<Tortue*> getListeTortuesFrom(Tortue* maTortue);

		string toString();
    friend ostream& operator<< (ostream &os, Case &c);
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

vector<Tortue*> Case::getListeTortues(void){
  return listeTortues;
}

vector<Tortue*> Case::getListeTortuesFrom(Tortue* maTortue){
	vector<Tortue*> ret;
	vector<Tortue*>::iterator tortueIterator;
	
	tortueIterator = find(listeTortues.begin(), listeTortues.end(), maTortue);
	//check maTortue presente dans la case
	if (tortueIterator != listeTortues.end() ){
		for (auto it = tortueIterator; it != listeTortues.end(); ++it) {
			Tortue* tortuePtr = *it;
			ret.push_back(tortuePtr);
		}
	}	else {	//maTortue pas présente sru cette case
		
	}
  return ret;
}


//--------------------------
//Méthodes diverses
//--------------------------

void Case::addTortue(Tortue* maTortue){
  maTortue->setPosition(numero);
	listeTortues.push_back(maTortue);
}

void Case::addTortues(vector<Tortue*> mesTortue){
	for(auto it = mesTortue.begin(); it != mesTortue.end(); ++it) {
		Tortue* tortuePtr = *it;
    tortuePtr->setPosition(numero);
		listeTortues.push_back(tortuePtr);
	}
	//maTortue->setPosition(numero);
	//listeTortues.push_back(maTortue);
}

void Case::removeTortue(Tortue* maTortue){
  vector<Tortue*>::iterator tortueIterator;
	tortueIterator = find(listeTortues.begin(), listeTortues.end(),maTortue);
  listeTortues.erase(tortueIterator);
}

void Case::removeTortues(vector<Tortue*> mesTortue){
	for(auto it = mesTortue.begin(); it != mesTortue.end(); ++it) {
		Tortue* tortuePtr = *it;
		vector<Tortue*>::iterator tortueIterator;
		tortueIterator = find(listeTortues.begin(), listeTortues.end(),tortuePtr);
		listeTortues.erase(tortueIterator);
	}
	
	//vector<Tortue*>::iterator tortueIterator;
	//tortueIterator = find(listeTortues.begin(), listeTortues.end(),maTortue);
	//listeTortues.erase(tortueIterator);
}


string Case::toString(){
	string s = "Case n.";
	s+= to_string(this->numero) + ": ";
	//s+= ":"
	if(this->listeTortues.size() == 0){
    s+= "- \n";
  }else{
    for(int i=0 ; i<this->listeTortues.size() ; i++){
      s+= this->listeTortues[i]->toString();
			s+= "; ";
    }
  s+= "\n";
	}
	return s;
}

//Affichage d'une case et des eventuelles tortues qu'elle contient
std::ostream& operator<< (ostream &os, Case &c){
  os << c.toString();
  return os;
}
