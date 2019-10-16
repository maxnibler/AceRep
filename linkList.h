//Maximillian H Nibler
//max.nibler@gmail.com
//https://github.com/maxnibler/

#include <string>
using namespace std;
struct node{
  int key;
  void* data;
  node *next;
};

class linkedList{
 private:
  node *head, *tail;
  int count;
 public:
  linkedList(){
    head = NULL;
    tail = NULL;
    count = 0;
  }

  void insert(int n, void* d){
    node* temp = new node;
    temp->data = d;
    temp->key = n;
    temp->next = NULL;

    if (head == NULL){
      head = temp;
      tail = temp;
    }else{
      tail->next = temp;
      tail = temp;
    }
    count++;
    return;
  }

  void remove(int n){
    node* temp = head;
    bool flag = true;
    if (temp->key == n){
      head = temp->next;
    }else{
      node* prev = temp;
      while(temp->key != n){
	if (temp == NULL){
	  flag = false;
	  break;
	}
	prev = temp;
	temp = temp->next;
      }
      if (flag){
	prev->next = temp->next;
	if (tail->key == n)tail = prev;
      }else return;
    }
    count--;
  }
      
  void* find(int n){
    node* temp = head;
    while(temp->key != n){
      if (temp == NULL)break;
      temp = temp->next;
    }
    if (temp == NULL) return NULL;
    return temp->data;
  }
  
};
