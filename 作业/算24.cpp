#include<stdio.h>
#include<math.h>

int search(double a[], int x){//��x������24����ݹ齵��x-1������24����
    if (x == 1 && fabs(a[1] - 24) <= 1e-6)
        return 1;//�ݹ����
    double b[6]; 
    int i, j, k, p;
    for (i = 1; i <= x - 1; i++)
        for (j = i + 1; j <= x; j++){//��x�����е������ó�������
            p = 1;
            for (k = 1; k <= x; k++){
                if (k != i && k != j){
                    b[p++] = a[k];
                }
            }
            //�ּ�����������������ļ�����
            b[p] = a[i] + a[j]; 
            if (search(b, x - 1))
                return 1;
            b[p] = a[i] * a[j]; 
            if (search(b, x - 1))
                return 1;
            b[p] = a[i] - a[j]; 
            if (search(b, x - 1))
                return 1;
            b[p] = a[j] - a[i]; 
            if (search(b, x - 1))
                return 1;
            if (a[j] != 0){
                b[p] = a[i] / a[j];
                if (search(b, x - 1))
                    return 1;
            }
            if (a[i] != 0){
                b[p] = a[j] / a[i];
                if (search(b, x - 1))
                    return 1;
            }
        }
    return 0;
}

int main(){
    double a[6];
    for (int i = 0; i < 4; ++i) {
        scanf("%lf", &a[i]);
    }
    int flag = search(a, 4);
    if (flag == 1)
        printf("Yes");
    else 
        printf("No");
    return 0;
}
