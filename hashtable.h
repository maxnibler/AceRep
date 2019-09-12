#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
bool none = false;
const int tableSize = 200;
class HashTableItem{
   public:
      int x;
      void* y;
   HashTableItem(int x, void* inp){
      this -> x = x;
      this -> y = inp;
   }
};
class HashMapTable {
   private:
      HashTableItem **t;
   public:
      HashMapTable() {
         t = new HashTableItem * [tableSize];
         for (int i = 0; i< tableSize; i++) {
            t[i] = NULL;
         }
      }
      int HashFunc(int x) {
         return x % tableSize;
      }
      void Insert(int x, void* y) {
         int h = HashFunc(x);
         while (t[h] != NULL && t[h]->x != x) {
            h = HashFunc(h + 1);
         }
         if (t[h] != NULL)
            delete t[h];
         t[h] = new HashTableItem(x, y);
      }
      void* SearchKey(int x) {
         int h = HashFunc(x);
         while (t[h] != NULL && t[h]->x != x) {
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL)
            return &none;
         else
            return t[h]->y;
      }
      void Remove(int x) {
         int h = HashFunc(x);
         while (t[h] != NULL) {
            if (t[h]->x == x)
               break;
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL) {
            cout<<"No Element found at key "<<x<<endl;
            return;
         } else {
            delete t[h];
         }
         cout<<"Element Deleted"<<endl;
      }
      ~HashMapTable() {
         for (int i = 0; i < tableSize; i++) {
            if (t[i] != NULL)
               delete t[i];
               delete[] t;
         }
      }
};
