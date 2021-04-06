#include<stdio.h>

int main(){
	int i,j,a,b,m;
	scanf("%d %d",&i,&j);
	a=loop(i); b=loop(j); m=(a>b)?a:b;
	printf("%d %d %d",i,j,m);
}
