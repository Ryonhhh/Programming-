#include<stdio.h>
#include<math.h>

int resolve(int n,int sub) {//nλ�ݹ鵱ǰ����subΪ��ǰ�ֽ�������������ֵ
	int ans = 0, i;
	if (n == 1)
		return 1;//�ݹ��������
	else {
		for (i = sub; i >= 2; i--)//���Ͻ絽2����ѭ��
			if (n % i == 0)
				ans += resolve(n / i, i);//n=an*a(n-1)...a1��anȷ��ʱ�ķֽ�����=n/an�ķֽ�����(�ݹ�ʽ)
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", resolve(n,n));//��ʼ�ݹ�������Ͻ綼Ϊn
	return 0;
}