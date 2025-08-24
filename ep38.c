/*************************************************************************
	> File Name: ep38.c
	> Author:pk 
	> Mail:1134@qq.com 
	> Created Time: Sat 23 Aug 2025 11:31:29 AM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int judgment(int x) {
    int j[9] = {0};
    j[0] = 1;
    while (x) {
        if(j[x % 10] == 1) return 0;
        j[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int len(int x) {
    return log10(x) + 1;
}

int add(int x, int y) {
    return x * pow(10, len(y)) + y;
}

int digit(int x, int *sum) {
    int num_h = 0;
    for (int i = 1; i < 1000; i++) {
        num_h = add(num_h, x * sum[i]);
        if (!(len(num_h) == 9 && judgment(num_h))) continue;
        break;
    }
    return num_h;
}

int main() {
    int sum[1000] = {0}, num = 0, z = 0;
    for (int x = 1; x < 1000; x++) {
        sum[x] = x;
        z = digit(x, sum);
        if (num < z) num = z; 
    }
    printf("%d\n", num);
    return 0;
}
