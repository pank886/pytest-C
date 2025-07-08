/*************************************************************************
	> File Name: ep14.c
	> Author:pk 
	> Mail:1134@qq.com 
	> Created Time: Tue 08 Jul 2025 10:23:25 PM CST
 ************************************************************************/
#include <stdio.h>

#define MAX_N 1000000

int length(long long n) {
    if (n == 1) return 1;
    if (n & 1) return length(n * 3 + 1) + 1;
    return length(n >> 1) + 1;
}

int main() {
    int x = 0, y = 0;
    for (int i = 1; i < MAX_N; i++) {
        int temp = length(i);
        if (temp <= x) continue;
        x = temp;
        y = i;
    }
    printf("x = %d, y = %d\n", x, y);
    return 0;
}

