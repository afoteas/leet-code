#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int initial_capacity = 8; // Start with some reasonable capacity
    int** ret = malloc(initial_capacity * sizeof(int*));
    *returnColumnSizes = malloc(initial_capacity * sizeof(int));
    *returnSize = 0;

    if (ret == NULL || *returnColumnSizes == NULL) {
        perror("Initial allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1, k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum > 0) {
                k--;
            } else if (sum < 0) {
                j++;
            } else {
                if (*returnSize == initial_capacity) {
                    initial_capacity *= 2;
                    ret = realloc(ret, initial_capacity * sizeof(int*));
                    *returnColumnSizes = realloc(*returnColumnSizes, initial_capacity * sizeof(int));
                }

                ret[*returnSize] = malloc(3 * sizeof(int));
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[j];
                ret[*returnSize][2] = nums[k];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                do { j++; } while (j < k && nums[j] == nums[j-1]);
                do { k--; } while (j < k && nums[k] == nums[k+1]);
            }
        }
    }
    return ret;
}