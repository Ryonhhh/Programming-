#include<stdio.h>

int cycle_count(int a,int b){
	int cnt=1,max=0,i,num;
	for (i = a; i <= b; i++) {
		num = i;
		while (num != 1) {
			if (num % 2 == 0)
				num = num/2;
			else
				num = num * 3 + 1;
			cnt++;
		}
		if (cnt > max) max = cnt;
		cnt = 1;
	}
	return max;
}

int main(){
	int a, b, cyc;
	char c;
	int i=0;
	i = 1;
	scanf("%d %d", &a, &b);
	cyc = cycle_count(a,b);
	printf("%d %d %d", a, b, cyc);
	while ((c = getchar()) != EOF) {
		scanf("%d %d",&a,&b);
		cyc=cycle_count(a,b);
		printf("\n%d %d %d",a,b,cyc);
	}
}
