#include<stdio.h>
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int energy;
    scanf("%d",&energy);
    int flag=0;
    int m,k;
    for(int i=0;i<n;i++){
        if(energy==0) break;
        m=a[i];
        k=i;
        if(flag==0){
            for(int j=i+1;j<n;j++){
                if(a[j]<m){
                    m=a[j];
                    k=j;
                }
            }
            flag=1;
        }
        else{
            for(int j=i+1;j<n;j++){
                if(a[j]>m){
                    m=a[j];
                    k=j;
                }
            }
            flag=0;
        }
        if(k!=i){
            swap(&a[k],&a[i]);
            energy--;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
