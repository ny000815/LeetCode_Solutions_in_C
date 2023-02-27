#include <stdio.h>

int maxSubArray(int* nums, int numsSize);

int main() {
    int nums1[] = {-2,1,-3,4,-1,2,1,-5,4};
    int numsSize1 = 9;
    int maxSum1 = maxSubArray(nums1, numsSize1);
    printf("Max subarray sum: %d\n", maxSum1);

    int nums2[] = {1};
    int numsSize2 = 1;
    int maxSum2 = maxSubArray(nums2, numsSize2);
    printf("Max subarray sum: %d\n", maxSum2);

    int nums3[] = {-2,1,-3,4,-1,2,1,-5,4};
    int numsSize3 = 9;
    int maxSum3 = maxSubArray(nums3, numsSize3);
    printf("Max subarray sum: %d\n", maxSum3);

    return 0;
}


int maxSubArray(int* nums, int numsSize) {
    int result = nums[0];
    int current_sum = nums[0];


    for (int i = 1; i < numsSize; i++) {
        if (current_sum < 0) {
            current_sum = nums[i];
        } else {
            current_sum += nums[i];
        }

        if (current_sum > result) {
            result = current_sum;
        }
    }

    return result;
}

