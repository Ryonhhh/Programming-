#include<stdio.h>

int main(){
	long long a,b;
	char c;
	scanf("%ld %ld",&a,&b);
	printf("%ld",a+b);
	while(scanf("%c",&c)!=EOF){
		printf("\n");
	    scanf("%ld %ld",&a,&b);
	    printf("%ld",a+b);
    }
	return 0;
} 
