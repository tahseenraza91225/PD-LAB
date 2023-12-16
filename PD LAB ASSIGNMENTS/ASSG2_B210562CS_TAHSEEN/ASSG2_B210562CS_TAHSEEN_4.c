#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n], i;
    for(i = 0; i<n; i++) scanf("%d", &a[i]);
    int k;
    scanf("%d", &k);
    int f = 0;
    for(i = 0; i<n; i++){
        if(a[i]==k){
            f = 1;
            printf("%d\n", i);
            break;
        }
    }
    if(f==0) printf("%d\n", f - 1);
}

