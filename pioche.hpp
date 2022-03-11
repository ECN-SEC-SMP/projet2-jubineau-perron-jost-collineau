#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "carte.hpp"
using namespace std;

class Pioche
{
  private:
    vector<Carte> vectCartes;

  public:
    Pioche(void);
    Carte piocher(void);

    string toString();
    friend std::ostream& operator<< (ostream &, Carte &);
};

Pioche::Pioche(void){
  //Créer la liste de carte dans l'ordre
  srand (time(NULL));
  cout << "Init Pioche Done!" << endl;
}

Carte Pioche::piocher(void){
  int num = rand() % (sizeof(vectCartes));
  cout << "[Pioche] Rand num = " << num << endl;
  Carte ret = vectCartes[num];
  
  //enleve la carte de la pioche
  vectCartes.erase(vectCartes.begin()+num);
  
  return ret;
}

string PiochetoString(void){
  string s;
  s = 
}

std::ostream& operator<< (ostream &os, Carte &c){
  os << c.toString();
  return os;
}