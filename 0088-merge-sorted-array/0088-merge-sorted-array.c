void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
        int i=0, j=0, k=0;
        int nums3[n+m];
        memcpy(nums3, nums1, (n+m)*sizeof(int));
        do {

            if(j == n || (nums3[i] < nums2[j] && i < m)){
                nums1[k++] = nums3[i++];
            }
            else{ 
                nums1[k++] = nums2[j++];
            }
        } while (k < n+m);
}
