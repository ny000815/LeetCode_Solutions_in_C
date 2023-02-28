#include <stdio.h>

int getSum(int a, int b);

int main() {
    int a = 1, b = 2;
    int sum = getSum(a, b);
    printf("%d\n", sum);
    
    a = 2, b = -3;
    sum = getSum(a, b);
    printf("%d\n", sum);
    
    return 0;
}

int getSum(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

