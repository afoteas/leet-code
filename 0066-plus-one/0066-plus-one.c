/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = 0;
    for(i=digitsSize-1; i> -1; i--) {
        if (digits[i] == 9) {
            digits[i]=0;
        } else {
            digits[i]++;
            break;
        }
    }
    if(i == -1) {
        *returnSize = digitsSize + 1;
        int *ret = (int*) malloc((*returnSize)*sizeof(int));
        memset(ret,0,*returnSize*sizeof(int));
        ret[0]= 1;
        return ret;
    } else {
        *returnSize = digitsSize;
        return digits;
    }
}