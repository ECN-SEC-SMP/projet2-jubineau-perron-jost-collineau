#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "typeDef.hpp"
#include "carte.hpp"
using namespace std;

//------------------------------------------------------------------------------
// @class Pioche
// 
//------------------------------------------------------------------------------

class Pioche
{
  private:
    vector<Carte*> vectCartes;

  public:
    Pioche(void);
    Carte piocher(void);

    string toString();
    friend std::ostream& operator<< (ostream &, Carte &);
};

//--------------------------
//Constructeur
//Crée la liste de carte dans l'ordre
//--------------------------
Pioche::Pioche(void){
  //Init random
  srand (time(NULL));

  int i = 0; // compteur

  vectCartes.insert(vectCartes.end(), {
    new Carte(pp, bleu),
    new Carte(p, bleu), new Carte(p, bleu), new Carte(p, bleu), new Carte(p, bleu), new Carte(p, bleu),
    new Carte(m, bleu), new Carte(m, bleu),
    
    new Carte(pp, vert),
    new Carte(p, vert), new Carte(p, vert), new Carte(p, vert), new Carte(p, vert), new Carte(p, vert),
    new Carte(m, vert), new Carte(m, vert),
    
    new Carte(pp, rouge),
    new Carte(p, rouge), new Carte(p, rouge), new Carte(p, rouge), new Carte(p, rouge), new Carte(p, rouge),
    new Carte(m, rouge), new Carte(m, rouge),
    
    new Carte(pp, jaune),
    new Carte(p, jaune), new Carte(p, jaune), new Carte(p, jaune), new Carte(p, jaune), new Carte(p, jaune),
    new Carte(m, jaune), new Carte(m, jaune),
    
    new Carte(pp, violet),
    new Carte(p, violet), new Carte(p, violet), new Carte(p, violet), new Carte(p, violet), new Carte(p, violet),
    new Carte(m, violet), new Carte(m, violet),

    new Carte(ff, multicolor), new Carte(m, multicolor),
    new Carte(f, multicolor), new Carte(f, multicolor), new Carte(f, multicolor),
    new Carte(p, multicolor), new Carte(p, multicolor), new Carte(p, multicolor), new Carte(p, multicolor), new Carte(p, multicolor),
    new Carte(m, multicolor), new Carte(m, multicolor)
  } );
  cout << "[Pioche] vectCartes size = " << vectCartes.size() << endl;
  cout << "[Pioche] Init Done!" << endl;
}

Carte Pioche::piocher(void){
  int num = rand() % (sizeof(vectCartes));
  cout << "[Pioche] Rand num = " << num << endl;
  Carte ret = *vectCartes[num];
  
  //enleve la carte de la pioche
  vectCartes.erase(vectCartes.begin()+num);
  
  return ret;
}

//--------------------------
//Méthodes diverses
//--------------------------

//Affiche l'ensemble de la pioche restante
string Pioche::toString(void){
  string s;
  vector<int> compteurCartes; //contient le nombre de carte selon leur symbole

  //Remplie le vecteur de 5 types de carte
  for(int i = 0 ; i < 5 ; i++)
    compteurCartes.push_back(0);

  //Parcour le deck et incremente le compteur
  for(int i = 0 ; i < vectCartes.size() ; i++){
    //cout << vectCartes[i]->toString() << endl;
    compteurCartes[vectCartes[i]->getSymbole()]++;
  }

  cout << "Pioche restante : " << endl
       << compteurCartes[0] << "cartes +" << endl
       << compteurCartes[1] << "cartes ++" << endl
       << compteurCartes[2] << "cartes -" << endl
       << compteurCartes[4] << "cartes f" << endl
       << compteurCartes[5] << "cartes ff" << endl;
  
  return s;
}

std::ostream& operator<< (ostream &os, Pioche &p){
  os << p.toString();
  return os;
}