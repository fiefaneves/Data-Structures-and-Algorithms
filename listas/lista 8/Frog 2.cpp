#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> stones(N);
    for (int i = 0; i < N; i++){
        cin >> stones[i];
    }
     
    vector<int> F(N, INF);
    F[0]= 0;

    for (int i = 0; i < N; i++){
        for (int j = i+1; j <= i+K; j++){
            if (j<N){
                F[j] = min(F[j], F[i]+abs(stones[j]-stones[i]));
            }
        }
    }
    cout << F[N-1];
    return 0;
}