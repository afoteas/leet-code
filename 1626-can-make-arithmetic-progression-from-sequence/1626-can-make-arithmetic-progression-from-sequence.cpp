class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());

        if (arr.size() == 0) {
            return true;
        }

        int diff = arr[1] - arr[0];
        for (size_t i = 2; i < arr.size(); i++) {
            if(arr[i]-arr[i-1] != diff) {
                return false;
            }
        }
        return true;
        
    }
};