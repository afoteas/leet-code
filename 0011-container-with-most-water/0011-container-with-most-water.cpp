class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l != r) {
            int h = min(height[l],height[r]);
            int a = (r-l)*h;
            ret = max(ret, a);
            if (height[l] > height[r]) {
                r--;
            }
            else {
                l++;
            }
        }
        return ret;
    }
};
