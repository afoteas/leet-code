class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> arrPair;
        vector<int> ret;
        int i=0;
        int rank=1;
        int previous;
        bool first = true;
        for(auto&a:arr) {
            arrPair.push_back(make_pair(a, i++));
        }
        sort(arrPair.begin(),arrPair.end());
        for(auto&a:arrPair) {
            if (first) {
                previous = a.first;
                a.first = rank;
                first= false;
            }
            else if(a.first == previous) {
                a.first = rank;
            } else {
                previous = a.first;
                a.first = ++rank;
            }
        }
        sort(arrPair.begin(), arrPair.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        for(auto&a:arrPair) {
            ret.push_back(a.first);
        }
        return ret;
        
    }
};