/*************************************************************************
	> File Name: ep33.c
	> Author:pk 
	> Mail:1134@qq.com 
	> Created Time: Thu 21 Aug 2025 10:12:07 PM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int x, int y) {
    return (b ? gcd(b, a % b) : a);
}

int digit(int a, int b) {
    
    return 1;
}

int main() {
    int a = 1, b = 1, c = 1;
    for (int x = 10; x < 100; x++) {
        for (int y = x + 1; y < 100; y++) {
            if (!(x % 10 || y % 10)) continue;
            if (digit(x, y)) continue;
            a *= x;
            b *= y;
            c = gcd(x, y);
            x /= c;
            y /= c;
        }
    }
    printf("%d\n", y);
    return 0;
}
