#include <algorithm>

using namespace std;

template< typename T >
typename std::vector<T>::iterator 
   insert_sorted( std::vector<T> & vec, T const& item )
{
    return vec.insert
        (
            std::upper_bound( vec.begin(), vec.end(), item ),
            item
        );
}

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int len = code.size();
        vector<string> ans;
        const vector<string> allowed { "electronics", "grocery", "pharmacy", "restaurant" };
        unordered_map<string, vector<string>> buckets;
        buckets.reserve(allowed.size());
        auto isValidCode = [](const string& s) {
            return !s.empty() && all_of(s.begin(),s.end(), [](char c) {return isalnum(static_cast<unsigned char>(c)) || c == '_';});
        };

        for (int i=0; i < len; ++i) {
            if(!isActive[i] || !isValidCode(code[i])) {
                continue;
            }
            // if (!allowed.count(businessLine[i])) {
            if (find(allowed.begin(), allowed.end(), businessLine[i]) == allowed.end()) {
                continue;
            }
            insert_sorted(buckets[businessLine[i]], code[i]);
        }
        for (const auto& key : allowed) {
            cout << "key:" << key << endl;
            auto it = buckets.find(key);
            if (it != buckets.end()) {
                ans.insert(ans.end(), it->second.begin(), it->second.end());
            }
        }
        return ans;
        
    }
};