//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <stdlib.h>
#include <ctime>
#include "utils.h"

using namespace std;

void stdSeed(){
  srand(time(NULL));
}

void seed(int x){
  srand(x);
}

int roll (int dX){
  int die = rand()%dX+1;
  return die;
}

void charStack::push(char c){
  data[++top] = c;
  top = top % 3;
}

char charStack::peek(){
  if (top == -1) return base;
  else return data[top];
}

char charStack::pop(){
  if (top == -1) return peek();
  else{
    char ret = data[top];
    top--;
    return ret;
  }
}

void charStack::setBase(char c){
  base = c;
}
