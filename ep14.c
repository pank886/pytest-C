/*************************************************************************
	> File Name: ep14.c
	> Author:pk 
	> Mail:1134@qq.com 
	> Created Time: Tue 08 Jul 2025 10:23:25 PM CST
 ************************************************************************/
#include <stdio.h>
// test line added for git commit
#define MAX_N 10000000
#define MAX_M 100000

int length(long long n, int *L) {
    if (n == 1) return 1;
    if (n < MAX_M && L[n]) return L[n];
    int res = ((n & 1) ? length(n * 3 + 1, L) : length(n >> 1, L)) + 1;
    if (n < MAX_M) L[n] = res;
    return res;
}

int main() {
    int x = 0, y = 0;
    int L[MAX_M] = {0};
    for (int i = 1; i < MAX_N; i++) {
        int temp = length(i, L);
        if (temp <= x) continue;
        x = temp;
        y = i;
    }
    printf("x = %d, y = %d\n", x, y);
    return 0;
}

