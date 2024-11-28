#include <bits/stdc++.h>

using namespace std;

bool valid(vector<vector<int>> &M, int l, int i){
    
}

bool qns(int l, vector<vector<int>> &M, int n){
    if (l == n){
        return true;
    }
    else{
        for (int i = 0; i < n; i++){
            if (valid(M, l, i)){
                M[l][i] = 1;
                if (qns(l+1, M, n)){
                    return true;
                }
                else{
                    M[l][i] = 0;
                }
            }
        }
        return false;
    }
}

int main(){

    return 0;
}