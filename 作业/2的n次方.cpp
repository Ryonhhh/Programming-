#include<stdio.h>
#include<math.h>

void Pow2(int n) {
	int a[100] = {};
	int i,z=0,j;
	a[99] = 1;//设置初始位
	for (i = 0; i < n; i++)
		for (j = 99; j >= 0; j--) {
			a[j] *= 2;
			a[j] += z;
			z = a[j] / 10;//进位
			a[j] = a[j] % 10;
		}
	for (i = 0; i < 100 && a[i] == 0; i++);
	for (; i < 100; i++)//从高位输出
		printf("%d", a[i]);
}

int main(){
	int a;
	scanf("%d", &a);
	Pow2(a);
	return 0;
}
