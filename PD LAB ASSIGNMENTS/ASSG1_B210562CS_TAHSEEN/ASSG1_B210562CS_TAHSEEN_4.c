#include <stdio.h>
int main(){
	char a[100000];
	scanf("%s", a);
	int fr[124] = {0};
	int i;
	for(i = 0; a[i]!='\0'; i++){
		fr[a[i]] = fr[a[i]] + i+1;
	}
	int max = 0;
	char maxi = max;
	for(i = 0; a[i]!='\0'; i++){
		if(max<=fr[a[i]]){
			max = fr[a[i]];
			maxi = a[i];
		}
	}
	for(i = 0; a[i]!='\0'; i++){
		if(max==fr[a[i]]){	
			printf("%c\n", a[i]);
			break;
		}
	}
}
