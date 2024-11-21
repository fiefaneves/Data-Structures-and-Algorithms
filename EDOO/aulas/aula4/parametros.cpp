//parametros de funções
#include <bits/stdc++.h>
using namespace std;

int fat (int num){
    if (num<=2){
        return num;
    }
    return num * fat(num-1);    
}

int quadrado(int v){
    return v*v;
}

int soma(int a, int b){
    // return quadrado(a)+quadrado(b);
    return a+b;
}

int main() {
    int a, b;
    cout << "Digite o primeiro número inteiro: "; 
    cin >> a;
    cout << "Digite o segundo número inteiro: "; 
    cin >> b;
    
    int sum = soma(a,b); // a e b = argumentos da função
    cout << "A soma dos dois numeros é: " << sum << "\n";
    cout << "O fatorial do num1 é: " << fat(a) << "\n";
    cout << "O fatorial do num2 é: " << fat(b) << "\n";

    return 0;
}