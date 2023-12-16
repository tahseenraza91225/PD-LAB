#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    char a[n];
    for(i = 0; i<n; i++) scanf(" %c", &a[i]);
    int j;
    char k;
    for(i = 1; i<n; i++){
        j = i-1;
        k = a[i];
        while(j>=0 && a[j]>k){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
    }
    for(i = n-1; i>=0; i--) printf("%c ", a[i]);
    printf("\n");
}
