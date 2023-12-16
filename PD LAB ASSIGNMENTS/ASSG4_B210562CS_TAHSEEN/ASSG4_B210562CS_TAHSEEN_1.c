#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    float a[n];
    for(i = 0; i<n; i++) scanf("%f", &a[i]);
    int j;
    float k;
    for(i = 1; i<n; i++){
        j = i-1;
        k = a[i];
        while(j>=0 && a[j]>k){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
    }
    for(i = 0; i<n; i++) printf("%0.2f ",a[i]);
}
