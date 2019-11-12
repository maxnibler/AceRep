extern bool active;

class Piece{
 private:
  int xCoor;
  int prevX;
  int yCoor;
  int prevY;
  char rep;
 public:
  void setLocation(int x, int y, char o);
  void horMove(int dist);
  void verMove(int dist);
  int getY();
  int getX();
  char getChar();
  void move();
};



char getDirection();
