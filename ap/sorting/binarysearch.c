#include <stdio.h>

void merge(int array[], int n, int f, int l){
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

void mergesort(int array[], int n, int f, int l){
    if(f<l){
        int m = (f+l)/2;
        mergesort(array, n, f, m);
        mergesort(array, n, m+1, l);
        merge(array, n, f, l);
    }
}

int binarysearch(int array[], int n, int f, int l, int k){
    if (l>=f){
        int m = (f+l)/2;
        if (k==array[m]){
            return m;
        }else{
            if(k<array[m]){
                return binarysearch(array, n, f, m-1, k);
            }else{
                return binarysearch(array, n, m+1, l, k);
            }
        }

    }else{
        return -1;
    }
}

int main()
{
    int n, k;
    int i;
    scanf("%d", &n);
    int array[n];
    for (i=0;i<n;i++){
        scanf("%d", &array[i]);
    }
    scanf("%d", &k);
    mergesort(array, n, 0, n-1);
    i=binarysearch(array, n, 0, n-1, k);
    if(i==-1){
        printf("x");
    }else{
        printf("%d", i);}
}