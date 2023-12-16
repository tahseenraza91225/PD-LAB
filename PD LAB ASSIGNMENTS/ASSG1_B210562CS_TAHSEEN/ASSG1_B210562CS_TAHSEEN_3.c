#include <stdio.h>
#include <math.h>
 float Pow(float p, int q){
	 float a = 1;
	int i;
	for(i = 0; i<q; i++) a = a*p;
	return a;
}
 float fac(int p){
	if(p<=1) return 1;
	return p* fac(p-1);
}
int main(){
	int n;
	float x;
	scanf("%f %d", &x, &n);
	x = x * (3.1415/180);
	int i;
	float s = 0;
	int c = 0;
	for(i = 1; i<=n; i = i+2){
		if(c%2==0) s = s + (float)(Pow(x, i)/fac(i));
		else s = s - (float)(Pow(x, i)/fac(i));
		c++;
	}
	printf("%0.4f\n", s);
}
