#include<stdio.h>

int check(int arr[],int n,int p){
    for(int i=0;i<n;i++){
        if(arr[i]==p){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    int new_arr[n];
    int idx = 0;
    int k;

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    scanf("%d",&k);
    int p = 1;
    int max = arr[n-1];
    
    while(p<=max){

        if(!check(arr,n,p)){
            new_arr[idx++] = p;
            p++;
        }
        else{
            p++;
            continue;
        }
    }
    int size = idx+1;

    if(k<=size)
    printf("%d\n",new_arr[k-1]);
    else
    printf("-1\n");
    
    return 0;
}
