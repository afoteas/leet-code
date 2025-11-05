#include <cmath>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    vector<int> p1 = points[i];
                    vector<int> p2 = points[j];
                    vector<int> p3 = points[k];
                    double currentArea = abs(0.5 * (p1.at(0)*(p2.at(1)-p3.at(1)) + p2.at(0)*(p3.at(1)-p1.at(1)) + p3.at(0)*(p1.at(1)-p2.at(1))));
                    maxArea = max(maxArea, currentArea);
                }
            }
        }
        return maxArea;
    }
};