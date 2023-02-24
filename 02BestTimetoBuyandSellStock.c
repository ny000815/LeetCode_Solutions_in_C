#include <stdio.h>

int maxProfit(int* prices, int pricesSize);

int main() {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int prices2[] = {7, 6, 4, 3, 1};
    int profit1 = maxProfit(prices1, 6);
    int profit2 = maxProfit(prices2, 5);
    printf("Max profit for prices1: %d\n", profit1);
    printf("Max profit for prices2: %d\n", profit2);
    return 0;
}

int maxProfit(int* prices, int pricesSize) {
    int i, j;
    int result = -1;//not 0
    int tmp = 0;
    for (i = 0; i < pricesSize - 1; i++) {
        for (j = i + 1; j < pricesSize; j++) {
            if (prices[i] < prices[j]) {
                tmp = prices[j] - prices[i];
                if (result < tmp) {
                    result = tmp;
                }
            }
        }
    }
    if (result < 0) {
        return 0;
    } else {
        return result;
    }
}

