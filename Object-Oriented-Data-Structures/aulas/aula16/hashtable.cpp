#include <bits/stdc++.h>

using namespace std;

template <typename T>
class HashTable
{
    private:
        vector<T> table; 
        int size; 
        int capacity;
        int hash(T key);
    public:
        HashTable(int capacity);
        void insert(T key);
        void remove(T key);
        bool search(T key);
};

int main()
{
    
}