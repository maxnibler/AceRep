//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "input.h"
#define DNUM 4

using namespace std;

const string directions[DNUM] = {"w", "a", "s", "d"};

int getDirection(){
  string input;
  cin >> input;
  for (int i = 0; i < DNUM; i++){
    if (input == directions[i]) return i;
  }
  return -1;
}
