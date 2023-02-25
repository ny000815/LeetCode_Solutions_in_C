#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool containsDuplicate(int* nums, int numsSize);

int main() {
    int nums1[] = {1, 2, 3, 1};
    int nums2[] = {1, 2, 3, 4};
    int nums3[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    bool result1 = containsDuplicate(nums1, size1);
    bool result2 = containsDuplicate(nums2, size2);
    bool result3 = containsDuplicate(nums3, size3);
    printf("Result 1: %s\n", result1 ? "true" : "false");
    printf("Result 2: %s\n", result2 ? "true" : "false");
    printf("Result 3: %s\n", result3 ? "true" : "false");
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    // Find the minimum and maximum values in nums
    int min = nums[0], max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min) {
            min = nums[i];
        } else if (nums[i] > max) {
            max = nums[i];
        }
    }
    
    // Use a hash set to store the unique elements
    bool set[max - min + 1];
    memset(set, false, sizeof(set));
    
    for (int i = 0; i < numsSize; i++) {
        int index = nums[i] - min;
        if (set[index]) {
            // Duplicate found
            return true;
        } else {
            set[index] = true;
        }
    }
    
    // No duplicates found
    return false;
}
/*
bool containsDuplicate(int* nums, int numsSize){
    for (int i =0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++)
            if (nums[i] == nums[j]) {
            return true;
        }
    }
    return false;
}
*/

