class Solution {
public:
    long long maxPointsMemory(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();

        auto mask = [&cols](int pos) {
            std::vector<int> res(cols);
            for (int i = 0; i < cols; ++i) {
                res[i] = -std::abs(i - pos);
            }
            return res;
        };

        for (int i = 1; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::vector<int> masked_prev_row = mask(j);
                for (int k = 0; k < cols; ++k) {
                    masked_prev_row[k] += points[i - 1][k];
                }
                points[i][j] = *std::max_element(masked_prev_row.begin(), masked_prev_row.end()) + points[i][j];
            }
        }

        return *std::max_element(points.back().begin(), points.back().end());
    }

    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();
        vector<vector<long long>> dp(rows, vector<long long>(cols, 0));
        for (int j=0; j<cols; j++) {
            dp[0][j]=points[0][j];
        }
        for (int i = 1; i < rows; ++i) {
            std::vector<long long> right(cols, 0);
            right.back() = dp[i-1].back();
            for (int j = cols-2; j > -1; --j) {
                right[j] = std::max(right[j+1]-1, dp[i-1][j]);
            }
            long long left = dp[i-1][0];
            dp[i][0] = std::max(left,right[0]) + points[i][0];
            for (int j = 1; j < cols; ++j) {
                left = std::max(left-1, dp[i-1][j]);
                dp[i][j]=std::max(left,right[j]) + points[i][j];
            }
        }

        return *std::max_element(dp.back().begin(), dp.back().end());
    }

    long long maxPointsChat(std::vector<std::vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();
        
        for (int i = 1; i < rows; ++i) {
            std::vector<int> right(cols, 0);
            right.back() = points[i - 1].back();
            
            for (int j = cols - 2; j >= 0; --j) {
                right[j] = std::max(right[j + 1] - 1, points[i - 1][j]);
            }
            
            int left = points[i - 1][0];
            points[i][0] = std::max(left, right[0]) + points[i][0];
            
            for (int j = 1; j < cols; ++j) {
                left = std::max(left - 1, points[i - 1][j]);
                points[i][j] = std::max(left, right[j]) + points[i][j];
            }
        }
        
        return *std::max_element(points.back().begin(), points.back().end());
    }
};


