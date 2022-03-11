#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

class Plateau
{
  private:
    

	public :
	  Plateau(string nomFichier);

    void printToFile(string fileName);
    string toString();
    friend std::ostream& operator<< (ostream &, Carte &);

    void addParcelle(Parcelle* p);
};

Carte::Carte(string nomFichier){
  
}

string Carte::toString(){
	
}

void Carte::printToFile(string fileName){

}

std::ostream& operator<< (ostream &os, Carte &c){
  os << c.toString();
  return os;
}