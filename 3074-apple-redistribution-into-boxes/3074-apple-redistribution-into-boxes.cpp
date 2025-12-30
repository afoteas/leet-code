class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int sum = std::accumulate(apple.begin(), apple.end(), 0);
        int ans = 0;
        for (auto &c : capacity) {
            if (sum > 0) {
                ans ++;
                sum -= c;
            }
        }
        return ans;
        
    }
};