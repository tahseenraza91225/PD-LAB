#include <stdio.h>
int mini(int p, float a[], int n){
    float min = a[p];
    int mini = p;
    for(int i = p; i<n; i++){
        if(min>=a[i]){
            min = a[i];
            mini = i;
        }
    }
    return mini;
}

int main()
{
    int n;
    scanf("%d", &n);
    float a[n];
    int i;
    for(i = 0; i<n; i++) scanf("%f", &a[i]);
    int j;
    float k;
    int d, x;
    scanf("%d %d", &x, &d);
    int c = 0;
    i = 0;
    while(c<d && i<n){
        int p = mini(i, a, n);
        k = a[p];
        j = p - 1;
        while(j>=0 && a[j]>k){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
        i++;
        c++;
    }
    for(i = 0; i<n; i++) printf("%0.2f ", a[i]);
    printf("\n");
}
