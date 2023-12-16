#include <stdio.h>
int main(){
	char S[10000], c;
	scanf(" %[^\n]s", S);
	scanf(" %c", &c);
	int i, p = 0;
	for(i = 0; S[i]!='\0'; i++){
		if(S[i]>=65 && S[i]<=90) S[i] = S[i] + 32;
	}
	for(i = 0; S[i]!='\0'; i++){
		if(S[i]==c) p++;
	}
	printf("%d\n", p);
}
