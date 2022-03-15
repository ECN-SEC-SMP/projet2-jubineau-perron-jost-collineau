#include <iostream>
#include "typeDef.hpp"
//#include "plateau.hpp"
//#include "carte.hpp"
#include "pioche.hpp"
//#include "joueur.hpp"

using namespace std;

int main() {
  cout << "------------------"	<< endl;
  cout << "CPP TP 6 note" 			<< endl;
  cout << "------------------"	<< endl;
  cout << "Editeurs : "					<<endl;
  cout << "   @GatienJost"			<< endl; 
  cout << "   @HugoCollineau" 	<< endl;
  cout << "   @YounPerron" 			<< endl;
  cout << "   @BastienJubineau"	<< endl << endl;
  
	//int nbJoueurs = 2;
  //cout << "Début du jeu avec " << nbJoueurs << " joueurs !"<< endl;
	
  //--------------------------
  //JEUX DE TESTS
  //--------------------------
	
	//CLASSE PLATEAU
	//Plateau monPlateau(5);
	//Joueur *joueur1 = new Joueur ("J1", bleu);
	//monPlateau.ajouterJoueur(joueur1);
	//Joueur *joueur2 = new Joueur ("J2", Couleur vert);
	//Joueur *joueur3 = new Joueur ("J3", Couleur rouge);
	//Joueur *joueur4 = new Joueur ("J4", Couleur jaune);
	//Joueur *joueur5 = new Joueur ("J2", Couleur violet);
	
  //CLASSE CARTE
	/* 
		Carte maCarte (p, vert);
		cout << maCarte;
	*/

  //CLASSE PIOCHE
    Pioche pioche;
    cout << pioche << endl;
  
  //CLASSE JOUEUR
  /*
    Joueur joueur1 ("TonyP", vert);
    joueur1.piocher_5_cartes(pile_de_cartes);
    joueur1.afficher_info_joueur();
	*/
}
