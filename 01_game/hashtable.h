//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include<string>
#define SIZE 200

using namespace std;

class hashtable{
private:
  linkedList table[SIZE];
public:
  hashtable(){
    for (int i = 0; i < SIZE; i++){
      table[i] = linkedList();
    }
  }

  void add(string skey, void* d){
    int key = hash(skey);
    int index = key % SIZE;
    table[index].insert(key, d);
  }

  void* get(string skey){
    int key = hash(skey);
    int index = key % SIZE;
    return table[index].find(key);
  }

  void remove(string skey){
    int key = hash(skey);
    int index = key % SIZE;
    return table[index].remove(key);
  }
  
  int hash(string str){
    int length = str.length();
    int total = 0, x;
    for (int i = 0; i < length; i++){
      x = static_cast<int>(str[i]);
      x *= i+10;
      total += x;
    }
    return total;
  }
};
