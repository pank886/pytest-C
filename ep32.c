/*************************************************************************
	> File Name: ep32.c
	> Author:pk 
	> Mail:1134@qq.com 
	> Created Time: Sun 13 Jul 2025 09:01:24 PM CST
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#define MAX_N 100000

int keep[MAX_N + 5] = {0};

int digits(int x) {
    return floor(log10(x)) + 1;
}

int add_to_num(int a, int *num) {
    while (a) {
        if (num[a % 10]) return 0;
        num[a % 10] = 1;
        a = a / 10;
    }
    return 1;
}

int LOG(int a, int b, int c) {
    if (digits(a) + digits(b) + digits(c) - 9) return 0;
    int num[10] = {0};
    num[0] = 1;
    int flag = 1;
    flag = flag && add_to_num(a, num);
    flag = flag && add_to_num(b, num);
    flag = flag && add_to_num(c, num);
    return flag;
}

int main() {
    int sum = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = a + 1; b < 10000; b++) {
            if (!LOG(a, b, a * b)) continue;
            if (keep[a * b]) continue;
            sum += a * b;
            keep[a * b] = 1;
        }
    }
    printf("%d\n", sum);
    return 0;
}
