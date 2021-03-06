#include <string>

class charStack{
 private:
  int top;
  char base;
  char data[3];
 public:
  char peek();
  char pop();
  void push(char c);
  void setBase(char c);
  charStack(){
    top = -1;
    base = '.';
  }
};

void stdSeed();

void seed(int x);

int roll(int dX);

void openLog(bool append);

void closeLog();

void logString(std::string logstr);

extern bool logging;
