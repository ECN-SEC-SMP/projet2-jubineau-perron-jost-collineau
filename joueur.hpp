#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

class Plateau;	//prédéclaration: permet d'éviter une dépendance cyclique

//--------------------------
// @class Joueur
// La classe Joueur permet d'abstraire un joueur physique à un objet dans 
// notre programme. 
// Un joueur peut payer un autre joueur, se déplacer sur le plateau de joueur
// et on peut en afficher les informations.
//--------------------------
class Joueur
{
  private :
    string nom;
    string couleur;
    vector<Carte*> cartes_en_main;

    

  public :
    Joueur();
    Joueur(string name, string couleur);

    void afficher_info_joueur();
};

//--------------------------
//Constructeurs
//--------------------------
Joueur::Joueur(){
	this->nom = "unnamed";
  this->couleur = "unnamed";
}

Joueur::Joueur(string name, string couleur)
{
  this->nom = name;   //on set le nom du joueur avec celui donné en paramètre
  this->couleur = couleur;
}

//--------------------------
// Affiche à l'écran toutes les informations sur le Joueur
//--------------------------
void Joueur::afficher_info_joueur()
{
  cout << "   INFO JOUEUR   " << endl;
  cout << "Nom = " << nom << endl;
  cout << "Tortue = " << couleur << endl;
  cout << " Cartes en main :" << endl;
  for(int i=0 ; i < cartes_en_main.size() ; i++){
    cout << "Carte " << i << " : " << to_string(cartes_en_main[i]->getSymbole()) << endl;
    cout << "      " << i << "   " << to_string(cartes_en_main[i]->getCouleur()) << endl;
  }
}