#pragma once
#include <iostream>
#include <vector>
#include "case.hpp"

using namespace std;

class Case
{
  private:
    vector<Tortue> listeTortues;
    int numero;

  public:
    Case(int num);
    vector<Tortue> getListeTortues(void);
    }
};

Case::Case(int num){
  this->numero = num;
}

vector<Tortue> Case::getListeTortues(void){
  return listeTortues;
}