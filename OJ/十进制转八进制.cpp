#include<cstdio>
#include<iostream>
int main() {
    char a[1000];
    int y = 0, k, n;
    scanf("%d", &n);
    if (n == 0) printf("0");
    else {
        while (n != 0) {
            y++;
            a[y] = n % 8;
            n = n / 8;
            a[y] = a[y] + '0';
        }
        for (int i = y; i > 0; i--)
            printf("%c", a[i]);
    }
    return 0;
}
