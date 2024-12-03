#include <bits/stdc++.h>

using namespace std;

// int main(){
//     int n;

//     cout << "Digite o número de elementos: ";
//     cin >> n;

//     vector<int> arr(n);
//     cout << "Digite uma lista de " << n << " numeros: \n";
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }

//     sort(arr.begin(), arr.end());

//     for (int i = 0; i < n; i++){
//         cout << arr[i] << ' ';
//     }
//     cout << '\n';

//     return 0;
// }

int main(){
    int n;

    cout << "Digite o número de elementos (1 <= n <= 100): ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        arr[i] = rand()%1001;
    }
    cout << "Array original: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';

    reverse(arr.begin(), arr.end());

    cout << "Array invertido: ";
    // for (int i = n-1; i >= 0; i--){
    //     cout << arr[i] << ' ';
    // }
    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}