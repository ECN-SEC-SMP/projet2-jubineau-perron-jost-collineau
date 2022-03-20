#include <iostream>
#include "typeDef.hpp"
#include "plateau.hpp"
#include "joueur.hpp"
//#include "carte.hpp"
//#include "pioche.hpp"
#include "tortue.hpp"
//#include "case.hpp"

using namespace std;

int main() {
  cout << "------------------"	<< endl;
  cout << "CPP TP 6 note" 			<< endl;
  cout << "------------------"	<< endl;
  cout << "Editeurs : "					<<endl;
  cout << "   @GatienJost"			<< endl; 
  cout << "   @HugoCo4llineau" 	<< endl;
  cout << "   @YounPerron" 			<< endl;
  cout << "   @BastienJubineau"	<< endl << endl;
  
	//==========================
  //PARTIE NORMALE
  //==========================
  
	Pioche pile_de_cartes;
	Joueur joueur1 ("Raphael", rouge, true);
	Joueur joueur2 ("Donatello", violet, true);
	Joueur joueur3 ("Leonardo", bleu, true);
	Joueur joueur4 ("Michelangelo", jaune, true);
	Joueur joueur5 ("Maître Splinter", vert, true);
  joueur1.piocher_5_cartes(pile_de_cartes);
  joueur2.piocher_5_cartes(pile_de_cartes);
  joueur3.piocher_5_cartes(pile_de_cartes);
  joueur4.piocher_5_cartes(pile_de_cartes);
  joueur5.piocher_5_cartes(pile_de_cartes);

	Plateau monPlateau;
	monPlateau.ajouterJoueur(&joueur1);
	monPlateau.ajouterJoueur(&joueur2);
	monPlateau.ajouterJoueur(&joueur3);
	monPlateau.ajouterJoueur(&joueur4);
	monPlateau.ajouterJoueur(&joueur5);

  //lancement d'une partie
	monPlateau.Jeu();

  //==========================
  //JEUX DE TESTS
  //==========================

	//-------------------
		//CLASSE PIOCHE
/*  
  Pioche piocheNormale;           //creation pioche
  cout << piocheNormale << endl;  //affichage de la pioche initiale
  for(int i=0 ; i<5 ; i++) //Pioche 5 cartes
    piocheNormale.piocher();
  cout << piocheNormale << endl;  //affiche la pioche finale
*/  
/*
  Pioche piocheVide;
  cout << piocheVide << endl;  //affichage de la pioche initiale
  for(int i=0 ; i<60 ; i++)     //Piocher toutes les cartes
    piocheVide.piocher();
  cout << piocheVide << endl;  //affiche la pioche finale
*/

	
//-------------------
	//CLASSE CARTE
/*
	Carte maCarte(m, violet); 
  cout << maCarte << endl; 
*/

	
	//-------------------
  	//CLASSE CASE
/*
  Tortue tortueBleue(bleu);
	Tortue tortueVerte(vert);
	Tortue tortueRouge(rouge);
	Tortue tortueJaune(jaune);
	Tortue tortueViolette(violet);
	
	Case c1(1), c2(2), c3(3);
	c1.addTortue(&tortueBleue);
	c1.addTortue(&tortueVerte);
	c1.addTortue(&tortueRouge);
	c1.addTortue(&tortueJaune);
	c1.addTortue(&tortueViolette);
  cout << "Case test :" << endl
			 <<  c1 << endl;
	
	vector <Tortue*> monVec = 
		c1.getListeTortuesFrom(&tortueJaune);
	c2.addTortues(monVec);
	c1.removeTortues(monVec);
	c1.removeTortue(&tortueBleue);  
	cout << "Case test après suppression " 
			 << endl << c1 << endl;
*/

	
//-------------------
	//CLASSE TORTUE
/*
	Tortue tortueBleue(bleu);
  Tortue tortueVerte(vert);
  Tortue tortueRouge(rouge);
  Tortue tortueJaune(jaune);
  Tortue tortueViolette(violet);
  
  cout << tortueBleue << ", "
       << tortueVerte << ", "
       << tortueRouge << ", "
       << tortueJaune << ", "
       << tortueViolette << endl;
  tortueBleue.setPosition(5);
  cout << "La position de la tortue " 
			 << tortueBleue << " est :" 
			 << tortueBleue.getPosition() << endl;
*/

	
	//-------------------
		//CLASSE JOUEUR
/*
	Pioche pile_de_cartes;
  Joueur joueur1("TonyP", vert, false);
  joueur1.piocher_5_cartes(pile_de_cartes);
  joueur1.afficher_info_joueur();
*/

	
	//-------------------
		//CLASSE PLATEAU
/*
  Pioche pile_de_cartes;
	Joueur joueur1 ("Raphael", rouge, true);
	Joueur joueur2 ("Donatello", violet, true);
	Joueur joueur3 ("Leonardo", bleu, true);
	Joueur joueur4 ("Michelangelo", jaune, true);
	Joueur joueur5 ("Maître Splinter", vert, true);
  joueur1.piocher_5_cartes(pile_de_cartes);
  joueur2.piocher_5_cartes(pile_de_cartes);
  joueur3.piocher_5_cartes(pile_de_cartes);
  joueur4.piocher_5_cartes(pile_de_cartes);
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
}
