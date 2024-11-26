//Roteiro

#include <bits/stdc++.h>

using namespace std;

int main(){
// Diferença entre alocação na pilha vs heap
// malloc e free 
// malloc = memory allocation
    double x = 10;

    void *v = malloc(sizeof(double));
    // double *n = new double;
    double *n = (double *)v;
    cout << *n << '\n';
    *n = 3.14;
    cout << *n << '\n';

    free(v);
    cout << *n << '\n';

// Arrays unidimensionais



    return 0;
}