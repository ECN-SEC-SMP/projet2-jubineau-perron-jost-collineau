#pragma once
#include <stdio.h>

using namespace std;

//------------------------------------------------------------------------------
// @library typeDef
// Cette librairie supporte les typeDef utilisés dans les différentes classes.
//------------------------------------------------------------------------------

//p = plus
//m = moins
//f = fleche
typedef enum{
  p = 0, //+
  pp,    //++
  m,     //-
  f,     //fleche
  ff     //double-fleche
}Symbole;

typedef enum{
  bleu = 0, 
	vert, 
	rouge, 
	jaune, 
	violet,
  multicolor
}Couleur;