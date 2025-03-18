//ponteiros
#include <bits/stdc++.h>

using namespace std;
const int INF = INT_MAX;

//1 byte = 8 bites

int main(){
    int i = 1024;
    cout << "valor de i: " << i << ".\n";
    cout << "tamanho de i: " << sizeof(i) << " bytes.\n";
    cout << "endereço de i: " << &i << ".\n\n";

    int *p = &i; //ponteiro para int
    cout << "valor de p: " << p << ".\n";
    cout << "tamanho de p: " << sizeof(p) << " bytes.\n";
    cout << "endereço de p: " << &p << ".\n";
    cout << "endereço de i a partir do ponteiro p: " << p << ".\n\n";
    
    int j = *p; //copiando o valor de i em j //int j = i; = mesma coisa
    cout << "valor de j: " << j << ".\n";
    cout << "tamanho de j: " << sizeof(j) << " bytes.\n";
    cout << "endereço de j: " << &j << ".\n";

    return 0;
}