#include<stdio.h>
#include<math.h>

int main() {
	unsigned long long a,i,k=0,min,max;
	unsigned long long b[100] = {}, c[100] = {};//��֤����ͼ��㲻Խ��
	scanf("%llu", &a);
	max = 2 * a;
	for (i = a + 1; i<=max; i++)//ͨ����֦�򻯲���
		if ((a * i + 1) % (i - a) == 0) {
			b[k] = i;
			c[k] = (a * i + 1) / (i - a);
			k++;
			max = (a * i + 1) / (i - a);//����b�����ֵ
		}
	min = b[0] + c[0];
	for (i = 0; i < k; i++) {
		if (b[i] + c[i] < min)
			min = b[i] + c[i];//ɸѡ��Сֵ
	}
	printf("%d", min);
	return 0;
}