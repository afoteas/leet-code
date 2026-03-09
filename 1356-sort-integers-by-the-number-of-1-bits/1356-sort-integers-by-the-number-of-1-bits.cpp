class Solution {
public:
    vector<int> sortByBitsMine(vector<int>& arr) {
        vector<int> ret;
        map<int,vector<int>> mapa;
        for(auto&a:arr) {
            bitset<14> b(a);
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

    vector<int> sortByBitsMedium(vector<int>& arr) {
        vector<pair<int,int>> p;

        for( int n : arr ){
            int count = __builtin_popcount(n);
            p.emplace_back(count, n);
        }

        vector<int>  ans;
        sort(p.begin(), p.end());
        for( pair<int,int> &pr : p ){
            ans.push_back(pr.second);
        }
        return ans;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin() , arr.end() , [](const int &a ,const int &b) {
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);
            if (count_a != count_b) {
                return count_a < count_b; 
            }
            else{
                return a < b;
            }
        });
        return arr;
    }
};