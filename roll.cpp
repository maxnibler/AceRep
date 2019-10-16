//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

//#include <iostream>
//#include <string>
//#include <stdio.h>
#include <stdlib.h>
//#include <fstream>
#include <ctime>
#include "roll.h"

using namespace std;

void stdSeed(){
  srand(time(NULL));
}
void seed(int x){
  srand(x);
}
int roll (int dX){
  int die = rand()%dX;
  return die;
}
