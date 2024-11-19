//tipos de dados
#include <bits/stdc++.h>

using namespace std;
const int INF = INT_MAX;

//1 byte = 8 bites

int main(){
    bool b = false;
    // int n = sizeof(b);
    // cout << "bool = " << b << "; size = " << n << " bytes.\n"; 

    char a = 'a';

    // int num = 1024;
    // int num = 0b01111111111111111111111111111111; //binario
    // int n = sizeof(num);
    // cout << "int = " << num << "; size = " << n << " bytes.\n"; 
    // int n_int = sizeof(INF);
    // cout << "int = " << INF << "; size = " << n_int << " bytes.\n"; 

    // long int num = 1234;    
    long int num = 0b0111111111111111111111111111111111111111111111111111111111111111; //binario
    int n = sizeof(num);
    cout << "int = " << num << "; size = " << n << " bits.\n"; 

    unsigned long int u_num = 10; //int sem sinal 
    //o ultimo bit nao é usado para armazenar o sinal
   
    float f = 3.14;

    string palavra = "palavra";
    // int n = sizeof(palavra);
    // cout << "palavra = " << palavra << "; size = " << n << " bytes.\n"; 

    return 0;
}