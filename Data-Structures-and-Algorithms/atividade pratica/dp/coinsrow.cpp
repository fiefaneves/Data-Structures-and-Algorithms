#include <bits/stdc++.h>

using namespace std;

int coinrowBottomUp(vector<int> C, int n){
    vector<int> F(n+1);
    F[0] = 0;
    F[1] = C[1];
    for (int i = 2; i <= n; i++){
        F[i] = max(C[i]+F[i-2], F[i-1]);
    }
    return F[n];
}

int coinrowTopDown(vector<int> C, int n){

}

int main(){

    return 0;
}