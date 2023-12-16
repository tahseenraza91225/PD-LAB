#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[m], i;
    for(i = 0; i<m; i++) scanf("%d", &a[i]);
    int max = a[0];
    for(i = 0; i<m; i++) if(max<=a[i]) max = a[i];
    int s = 0;
    int p = 0;
    while(p!=n){
        s = 0;
        for(i = 0; i<m; ){
            if(s+ a[i]>max){
                s = 0;
                p++;
            }
            else{
                s = s + a[i];
                i++;
            }
        }
        p++;
        if(p!=n){
            max++;
            p = 0;
        }
        else break;
    }
    printf("%d\n", max);
}
