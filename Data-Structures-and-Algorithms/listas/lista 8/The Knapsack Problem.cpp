#include <bits/stdc++.h>

using namespace std;

int Knapsack(int n, int W, vector<int> &w, vector<int> &v){
    vector<vector<int>> F(n+1, vector<int>(W+1, 0));

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= W; j++){
            if (i == 0 || j == 0){
                F[i][j] = 0;
            } 
            else if (w[i-1] <= j){
                F[i][j] = max(F[i-1][j], v[i-1] + F[i-1][j-w[i-1]]);
            } 
            else{
                F[i][j] = F[i-1][j];
            }
        }
    }
    return F[n][W];
}

int main(){
    int S, N;
    cin >> S >> N;
    vector<int> sizes(N);
    vector<int> values(N);

    for (int i = 0; i < N; i++){
        cin >> sizes[i] >> values[i];
    }

    cout << Knapsack(N, S, sizes, values) << '\n';
    return 0;
}
