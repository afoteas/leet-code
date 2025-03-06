class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        // Merging the two arrays
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        
        // Sort the merged array by the first element of each inner vector
        sort(nums1.begin(), nums1.end());
        
        vector<vector<int>> result;
        
        for (const auto& n : nums1) {
            if (result.empty()) {
                result.push_back(n);
            } else {
                if (result.back()[0] == n[0]) {
                    result.back()[1] += n[1]; // Combine values
                } else {
                    result.push_back(n);
                }
            }
        }

        return result;
    }
};