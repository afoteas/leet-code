class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ret;
        map<int,vector<int>> mapa;
        for(auto&a:arr) {
            bitset<16> b(a);
            mapa[b.count()].push_back(a);
        }
        for(auto&[count,list]:mapa) {
            sort(list.begin(),list.end());
            for(auto& l:list) {
                ret.push_back(l);
            }
        }
        return ret;
    }
};