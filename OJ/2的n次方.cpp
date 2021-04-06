#include<stdio.h>
#include<math.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", (int)pow(2,n));
	}
}
