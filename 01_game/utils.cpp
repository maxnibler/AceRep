//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <stdlib.h>
#include <ctime>
#include "utils.h"

using namespace std;

FILE* logfile;
int count;

void openLog(bool append){
  if (append)
    logfile = fopen("Files/game.log", "a");
  else
    logfile = fopen("Files/game.log", "w");
  time_t stime = time(nullptr);
  count = 0;
  string localt = asctime(localtime(&stime));
  fprintf(logfile,"Logging from time: %s", localt.c_str());
}

void closeLog(){
  fprintf(logfile,"Game exited normally\n");
  fclose(logfile);
}

void logString(string logstr){
  fprintf(logfile, "  %4d| %s", count++, logstr.c_str());
}

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
