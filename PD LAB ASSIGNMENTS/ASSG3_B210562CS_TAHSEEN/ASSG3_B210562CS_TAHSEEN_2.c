#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n], i;
    for(i = 0; i<n; i++) scanf("%d", &a[i]);
    int j, k;
    for(i = 1; i<n; i++){
        k = a[i];
        j = i - 1;
        while(j>=0 && a[j]>k){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
    }
    for(i = 0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
}
