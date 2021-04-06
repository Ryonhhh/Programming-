#include<stdio.h>
#include<math.h>

int resolve(int n,int sub) {//n位递归当前数，sub为当前分解的质因数的最大值
	int ans = 0, i;
	if (n == 1)
		return 1;//递归结束条件
	else {
		for (i = sub; i >= 2; i--)//从上界到2进行循环
			if (n % i == 0)
				ans += resolve(n / i, i);//n=an*a(n-1)...a1在an确定时的分解种数=n/an的分解种数(递归式)
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", resolve(n,n));//初始递归的数和上界都为n
	return 0;
}