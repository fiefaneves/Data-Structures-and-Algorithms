//manipulação de arquivos
#include <bits/stdc++.h>
#include "prime.h"

using namespace std;

int main(){
    int a;
    cout << "Enter a positive integer:\n";
    cin >> a;
    if (is_prime(a)){
        cout << a << " is prime\n";
    }
    else{
        cout << a << " is not prime\n";
    }
    return 0;
}