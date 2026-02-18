class Solution {
public:

    void combineHelper(int start, int k, vector<int>& nums, vector<int>& path, 
                     vector<string>& result) {
        // Base case: selected k elements
        if (path.size() == k) {
            int minutes = 0;
            int hours = 0;
            for(int p: path) {
                if (p>0) minutes += p;
                else hours-=p;

            }
            if (hours < 12 && minutes < 60) {
                char buffer[6];
                sprintf(buffer, "%d:%02d", hours, minutes);
                result.push_back(string(buffer));
            }
            return;
        }
        for (int i = start; i < nums.size(); i++) {
                path.push_back(nums[i]);
                combineHelper(i+1, k, nums, path, result);
                path.pop_back();

        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        vector<int> nums = {1, 2, 4, 8, 16, 32, -1, -2, -4, -8};
        vector<int> path;
        
        combineHelper(0, turnedOn, nums, path, result);

        return result;
        
    }
};