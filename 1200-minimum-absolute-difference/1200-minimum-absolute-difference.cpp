class Solution {
public:
    vector<vector<int>> minimumAbsDifferenceFirst(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int min = (arr.at(1) - arr.at(0));
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr.at(i) - arr.at(i-1);
            if (min > diff) {
                min = diff;
            }
        }

        for (int i = 1; i < arr.size(); i++) {
            int diff = arr.at(i) - arr.at(i-1);
            if (diff == min) {
                ans.push_back(vector<int>({arr.at(i-1) , arr.at(i)}));
            }
        }
        return ans;
    }

    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int min = (arr.at(1) - arr.at(0));
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr.at(i) - arr.at(i-1);
            if (min > diff) {
                min = diff;
            }
        }

        for (int i = 1; i < arr.size(); i++) {
            int diff = arr.at(i) - arr.at(i-1);
            if (diff == min) {
                ans.push_back(vector<int>({arr.at(i-1) , arr.at(i)}));
            }
        }
        return ans;
    }
};