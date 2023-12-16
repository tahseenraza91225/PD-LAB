#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    int i;
    for(i = 0; i<n; i++) scanf("%d", &a[i]);
    int fr[10001] = {0};
    for(i = 0; i<n; i++) fr[a[i]]++;
    int p = 10000;
    while(k--){
        for(i = p; i>=0; i--){
            if(fr[i]>0){
                printf("%d ", i);
                p = i - 1;
                break;
            }
        }
    }
}
