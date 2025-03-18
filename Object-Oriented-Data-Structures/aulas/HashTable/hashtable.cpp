#include <bits/stdc++.h>
#include "list.hpp"

using namespace std;
using Key_t = unsigned int;

class HashTable
{
    private:
        LinkedList<Key_t> *table; 
        int sz; 
        int capacity;
        double maxLoad = 0.7;
        size_t hash(Key_t key);

        void rehash(){
            if (loadFactor() < maxLoad) return;
            HashTable new_table(capacity*2);
            for (int i = 0; i < capacity; i++){
                LinkedList<Key_t> &list = table[i];
                for (int j = 0; j < list.size(); j++){
                    int key = list[j];
                    new_table.insert(key);
                }
            }
            capacity = new_table.capacity;
            delete[] table;
            table = new_table.table;
            new_table.table = nullptr;
        }

    public:
        HashTable(size_t cap): sz{0}, capacity{cap}, table{new LinkedList<Key_t>[cap]} {};
        ~HashTable(){
            delete[] table;
        }
        
        size_t size() const {return sz;}
        size_t cap() const {return capacity;}
        double loadFactor() const {return (double)sz/capacity;}

        bool contains(Key_t key){
            size_t pos = hash(key);
            LinkedList<Key_t> &list = table[pos];
            int i = list.search(key);
            return i >= 0;
        }

        bool insert(Key_t key){
            if (contains(key)) return false;
            rehash();
            size_t pos = hash(key);
            LinkedList<Key_t> &list = table[pos];
            // if (list.search(key)>=0) return false;
            list.prepend(key);
            sz++;
            return true;
        }

        bool remove(Key_t key){
            size_t pos = hash(key);
            LinkedList<Key_t> &list = table[pos];
            int i = list.search(key);
            if (i < 0) return false;
            list.remove(i);
            sz--;
            return true;
        }

        void printTable(){
            for (int i = 0; i < capacity; i++){
                cout << i << ": ";
                LinkedList<Key_t> &list = table[i];
                for (int j = 0; j < list.size(); j++){
                    cout << list[j] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    
}