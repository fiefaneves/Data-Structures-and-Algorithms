#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int bars[], int n, int f, int l){
    int temp[n];
    for(int i=f;i<=l;i++){
        temp[i] = bars[i];
    }
    int m = (f+l)/2;
    int i1=f, i2=m+1;
    for (int j=f;j<=l;j++){
        if(i1==m+1){
            bars[j]=temp[i2++];
        }
        else{
            if(i2>l){
                bars[j] = temp[i1++];
            }
            else{
                if(temp[i1]<=temp[i2]){
                    bars[j]=temp[i1++];
                }
                else{
                    bars[j]=temp[i2++];
                }
            }
        }
    }
}

void mergesort(int bars[], int n, int f, int l){
    if(f<l){
        int m = (f+l)/2;
        mergesort(bars, n, f, m);
        mergesort(bars, n, m+1, l);
        merge(bars, n, f, l);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int numbers[n];
    for(int i=0;i<n;i++){
        scanf("%d", &numbers[i]);
    }
    mergesort(numbers, n, 0, n-1);

    int total=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            float diff = numbers[i]-numbers[j];
            if(fabs(diff)==abs(k)){
                total++;
            }
            else{
                if(fabs(diff)>abs(k)){
                    break;
                }
            }
        }
    }
    printf("%d", total);    
}