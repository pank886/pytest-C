/*************************************************************************
	> File Name: ep17.c
	> Author:pk 
	> Mail:1134@qq.com 
	> Created Time: Thu 10 Jul 2025 10:37:54 PM CST
 ************************************************************************/
#include <stdio.h>

#define MAX_N 1000

int nub_name(int x) {
    static int ones_digit[20] = {
        0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
        6, 6, 8, 8, 7, 7, 9, 8, 8
    };
    static int tens_digit[10] = {
        0, 0, 6, 6, 5, 5, 5, 7, 6, 6
    };
    if (x < 20) return ones_digit[x];
    if (x < 100) return tens_digit[x / 10] + ones_digit[x % 10];
    if (x < 1000) {
        if (x % 100 == 0) return ones_digit[x / 100] + 7;
        return ones_digit[x / 100] + 10 + nub_name(x % 100);
    }
    return 11;
}

int main() {
    int nub = 0;
    for (int i = 1; i <= MAX_N; i++) {
        nub += nub_name(i);
    }
    printf("%d\n", nub);
    return 0;
}

