#include <iostream>
#include "typeDef.hpp"
#include "joueur.hpp"
#include "plateau.hpp"
//#include "carte.hpp"
#include "pioche.hpp"
#include "tortue.hpp"
#include "case.hpp"

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
  //NE PAS MODIFER CE JEUX DE TEST PAR PITIÉE (juste (de)commenter)

    Pioche piocheNormale;           //creation pioche
    cout << piocheNormale << endl;  //affichage de la pioche initiale
    for(int i=0 ; i<5 ; i++) //Pioche 5 cartes
      piocheNormale.piocher();
    cout << piocheNormale << endl;  //affiche la pioche finale

/*
    Pioche piocheVide;
    cout << piocheVide << endl;  //affichage de la pioche initiale
    for(int i=0 ; i<60 ; i++)     //Piocher toutes les cartes
      piocheVide.piocher();
    cout << piocheVide << endl;  //affiche la pioche finale
*/

  
	//CLASSE PLATEAU
  /*
	  Pioche pile_de_cartes;
		Joueur joueur1 ("A", bleu);
    joueur1.piocher_5_cartes(pile_de_cartes);
		Joueur joueur2 ("B", vert);
    joueur2.piocher_5_cartes(pile_de_cartes);
		Joueur joueur3 ("C", rouge);
    joueur3.piocher_5_cartes(pile_de_cartes);
		Joueur joueur4 ("D", jaune);
    joueur4.piocher_5_cartes(pile_de_cartes);
		Joueur joueur5 ("E", violet);
    joueur5.piocher_5_cartes(pile_de_cartes);
		
    Plateau monPlateau;
		monPlateau.ajouterJoueur(&joueur1);
		monPlateau.ajouterJoueur(&joueur2);
		monPlateau.ajouterJoueur(&joueur3);
		monPlateau.ajouterJoueur(&joueur4);
		monPlateau.ajouterJoueur(&joueur5);

    //lancement d'une partie
		monPlateau.Jeu();
*/
	
  //CLASSE JOUEUR
  /*
    Joueur joueur1 ("TonyP", vert);
    joueur1.piocher_5_cartes(pile_de_cartes);
    joueur1.afficher_info_joueur();
	*/

  //CLASSE TORTUE
  /*
  Tortue tortueBleue(bleu);
  Tortue tortueVerte(vert);
  Tortue tortueRouge(rouge);
  Tortue tortueJaune(jaune);
  Tortue tortueViolette(violet);
  */
	
	/*
  cout << tortueBleue << ", "
       << tortueVerte << ", "
       << tortueRouge << ", "
       << tortueJaune << ", "
       << tortueViolette << endl;
  */

  //CLASSE CASE
  /*
  Case c1(1), c2(2), c3(3);
  c1.addTortue(&tortueBleue);
	c1.addTortue(&tortueVerte);
	c1.addTortue(&tortueRouge);
	c1.addTortue(&tortueJaune);
	c1.addTortue(&tortueViolette);
  cout << c1 << endl;
	c1.removeTortue(&tortueVerte);  
	cout << c1 << endl;
*/
  
}
