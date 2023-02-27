/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize);

int main() {
    int nums[] = {1, 2, 3, 4};
    int numsSize = 4;
    int* result;
    int returnSize;

    result = productExceptSelf(nums, numsSize, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(numsSize * sizeof(int));
    int* right = malloc(numsSize * sizeof(int));
    int* left = malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        right[i] = 1;
        left[i] = 1;
    }
    
    // i should start from numsSize - 1 to correctly compute right array
    for (int i = numsSize - 1; i > 0; i--) {
        right[i-1] = right[i] * nums[i];
    }
    for (int i = 0; i < numsSize - 1; i++) {
        left[i+1] = left[i] * nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        result[i] = right[i] * left[i];
    }
    *returnSize = numsSize;
    return result;
}
