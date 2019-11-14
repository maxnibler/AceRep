//Maximillian Nibler

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "charStack.h"

using namespace std;

void charStack::push(char c){
  data[++top] = c;
  top = top % 10;
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
