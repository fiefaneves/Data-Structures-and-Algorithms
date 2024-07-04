#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoarepartition(int array[], int n, int f, int l){
    int p=array[f];
    int i=f;
    int j=l+1;    
    while (i<j)
    {   
        do
        {
            i++;
        } while (array[i]<p && i<l);
        do
        {
            j--;
        } while (array[j]>p);
        swap(&array[i], &array[j]);
    }
    swap(&array[i], &array[j]);
    swap(&array[f], &array[j]);
    return j;
}

void quicksort(int array[], int n, int f, int l){
    if (f<l){
        int s;
        s = hoarepartition(array, n, f, l);
        quicksort(array, n, f, s-1);
        quicksort(array, n, s+1, l);
    }
}

int main()
{
    int n;
    int i;
    scanf("%d", &n);
    int array[n];
    for (i=0;i<n;i++){
        scanf("%d", &array[i]);
    }
    quicksort(array, n, 0, n-1);
    for(i=0;i<n;i++){
        printf("%d ", array[i]);
    }
}
