class charStack{
 private:
  int top;
  char base;
  char data[10];
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
