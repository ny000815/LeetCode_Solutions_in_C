#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int i, j = 0;
    for (i = 1; i < numsSize; i++) {
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }
    return j + 1;
}
int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int expectedNums[] = {0, 1, 2, 3, 4, -1, -1, -1, -1, -1};
    int k = removeDuplicates(nums, 10);

    printf("Output: %d, nums = [", k);
    for (int i = 0; i < k; i++) {
        printf("%d", nums[i]);
        if (i != k - 1) {
            printf(",");
        }
    }
    for (int i = k; i < 10; i++) {
        printf(",_");
    }
    printf("]\n");

    return 0;
}


