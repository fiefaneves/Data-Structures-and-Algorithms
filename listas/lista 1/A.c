#include <stdio.h>

void merge(long long int bars[], long long int n, int f, int l){
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

void mergesort(long long int bars[], long long int n, int f, int l){
    if(f<l){
        int m = (f+l)/2;
        mergesort(bars, n, f, m);
        mergesort(bars, n, m+1, l);
        merge(bars, n, f, l);
    }
}

int main()
{
    long long int n, sum=0;
    int i;
    scanf("%lld", &n);
    long long int bars[n];
    for (i=0;i<n;i++){
        scanf("%lld", &bars[i]);
        sum+=bars[i];
    }
    mergesort(bars, n, 0, n-1);

    long long int m;
    scanf("%lld", &m);
    long long int coupons[m];
    for (i=0;i<m;i++){
        scanf("%lld", &coupons[i]);
        sum-=bars[n-coupons[i]];
        printf("%lld\n", sum);
        sum+=bars[n-coupons[i]];
    }
}