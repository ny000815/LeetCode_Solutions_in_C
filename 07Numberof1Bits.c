#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n);
int main(){
    uint32_t n1 = 0b00000000000000000000000000001011;
    uint32_t n2 = 0b00000000000000000000000010000000;
    uint32_t n3 = 0b11111111111111111111111111111101;

    int result1 = hammingWeight(n1);
    int result2 = hammingWeight(n2);
    int result3 = hammingWeight(n3);

    printf("%d\n", result1);
    printf("%d\n", result2);
    printf("%d\n", result3);
    return 0;
}

int hammingWeight(uint32_t n) {
    int result = 0;
    for (int i=31; i >= 0; i--){
        if(n%2 == 1){
            result++;
        }
        n = n >> 1;
    }
    return result;
}

/*
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}
*/
