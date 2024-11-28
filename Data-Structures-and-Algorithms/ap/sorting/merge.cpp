#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void merge(long long int array[], long long int n, int f, int l){
    int temp[n];
    for(int i=f;i<=l;i++){
        temp[i] = array[i];
    }
    int m = (f+l)/2;
    int i1=f, i2=m+1;
    for (int j=f;j<=l;j++){
        if(i1==m+1){
            array[j]=temp[i2++];
        }
        else{
            if(i2>l){
                array[j] = temp[i1++];
            }
            else{
                if(temp[i1]<=temp[i2]){
                    array[j]=temp[i1++];
                }
                else{
                    array[j]=temp[i2++];
                }
            }
        }
    }
}

void mergesort(long long int array[], long long int n, int f, int l){
    if(f<l){
        int m = (f+l)/2;
        mergesort(array, n, f, m);
        mergesort(array, n, m+1, l);
        merge(array, n, f, l);
    }
}

int main()
{
    long long int n;
    cin >> n;
    long long int array[n];
    for (int i=0;i<n;i++){
        cin >> array[i];
    }
    mergesort(array, n, 0, n-1);
    for(int i=0;i<n;i++){
        cout << array[i] << ' ';
    }cout << endl;
}