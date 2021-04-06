#include<stdio.h>

int main(){
	int a[11]={0,1,1,2,3,5,8,13,21,34,55};
	int i,k,c;
	scanf("%d",&i);
	/*for(k=0;k<11;k++)
	    if(a[k]==i){
	        printf("The Fibonacci number for %d is %d",i,k);
	        break;
	    }*/
	while(scanf("%c",&c)!=EOF){
		printf("\n");
		scanf("%d",&i);
		for(k=0;k<10;k++)
	        if(a[k]==i)
	            printf("The Fibonacci number for %d is %d",i,k);
	}
	return 0;
}
