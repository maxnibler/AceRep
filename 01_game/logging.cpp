//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <fstream>
#include <ctime>
#include "logging.h"

using namespace std;

FILE* logfile;
int count;

void openLog(bool append){
  if (append)
    logfile = fopen("game.log", "a");
  else
    logfile = fopen("game.log", "w");
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
