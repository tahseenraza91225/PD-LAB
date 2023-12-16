#include <stdio.h>
int maxi(int a[], int n, int p){
    int i;
    int max = a[p], maxi = p;
    for(i = p; i<n; i++) if(max<=a[i]){
        max = a[i];
        maxi = i;
    }
    return maxi;
}
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n], i;
    for(i = 0; i<n; i++) scanf("%d", &a[i]);
    int p;
    for(i = 0; i<n; i++){
        p = maxi(a, n, i);
        swap(&a[p], &a[i]);
    }
    for(i = 0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
}
