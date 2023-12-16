#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i<n; i++) scanf("%d", &a[i]);
    int j;
    int k;
    for(i = 1; i<n; i++){
        j = i-1;
        k = a[i];
        while(j>=0 && a[j]>k){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
    }
    for(i = 0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
}
