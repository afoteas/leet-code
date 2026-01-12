class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int len = points.size();
        for (int i = 1; i < len; ++i) {
            int px = points[i-1][0] , py = points[i-1][1];
            int nx = points[i][0] , ny = points[i][1]; 
            int ax = abs(px-nx);
            int ay = abs(py-ny);
            int d = min(ax, ay);
            int s = max(ax, ay) - d;
            ans += (d+s);


        }
        return ans;
    }
};