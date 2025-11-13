#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 * LeetCode 1. Two Sum (C)
 * Implements a simple open-addressing hash table (linear probing) to map
 * value -> index. Time O(n), extra space O(n).
 *
 * Function signature matches LeetCode's expected C solution:
 *   int* twoSum(int* nums, int numsSize, int target, int* returnSize);
 */

static uint64_t mix_uint64(uint64_t z) {
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    z = z ^ (z >> 31);
    return z;
}

static int find_in_table(int *keys, int *vals, char *occ, int capacity, int key) {
    uint64_t h = mix_uint64((uint64_t)key);
    int idx = (int)(h % (uint64_t)capacity);
    while (occ[idx]) {
        if (keys[idx] == key) return vals[idx];
        idx++;
        if (idx >= capacity) idx = 0;
    }
    return -1; /* not found */
}

static void put_in_table(int *keys, int *vals, char *occ, int capacity, int key, int val) {
    uint64_t h = mix_uint64((uint64_t)key);
    int idx = (int)(h % (uint64_t)capacity);
    while (occ[idx]) {
        if (keys[idx] == key) {
            vals[idx] = val;
            return;
        }
        idx++;
        if (idx >= capacity) idx = 0;
    }
    occ[idx] = 1;
    keys[idx] = key;
    vals[idx] = val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;
    if (numsSize < 2) return NULL;

    int capacity = numsSize * 2 + 1; /* simple sizing */
    int *keys = (int*)malloc(sizeof(int) * capacity);
    int *vals = (int*)malloc(sizeof(int) * capacity);
    char *occ = (char*)calloc(capacity, sizeof(char));
    if (!keys || !vals || !occ) {
        free(keys); free(vals); free(occ);
        return NULL;
    }

    for (int i = 0; i < numsSize; ++i) {
        int complement = target - nums[i];
        int found = find_in_table(keys, vals, occ, capacity, complement);
        if (found != -1) {
            int *res = (int*)malloc(sizeof(int) * 2);
            res[0] = found;
            res[1] = i;
            *returnSize = 2;
            free(keys); free(vals); free(occ);
            return res;
        }
        /* insert current value -> index */
        put_in_table(keys, vals, occ, capacity, nums[i], i);
    }

    free(keys); free(vals); free(occ);
    return NULL; /* no solution found */
}

#ifdef LOCAL
/* simple test harness when compiled locally with -DLOCAL */
int main(void) {
    int arr[] = {2,7,11,15};
    int size;
    int *res = twoSum(arr, 4, 9, &size);
    if (res) {
        printf("%d %d\n", res[0], res[1]);
        free(res);
    } else {
        printf("No solution\n");
    }
    return 0;
}
#endif
