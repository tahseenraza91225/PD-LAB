#include <stdio.h>
void printnum(int k, int n){
	if(n>=k){
		printf("%d ", k);
		printnum(k+1, n);
	}
	else return ;
}
int main(){
	int n;
	scanf("%d", &n);
	printnum(1, n);
	printf("\n");
}
