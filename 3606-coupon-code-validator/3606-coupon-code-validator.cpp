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
        vector<string> electronics;
        vector<string> grocery;
        vector<string> pharmacy;
        vector<string> restaurant;
        vector<string> ans;
        std::string str_electronics("electronics");
        std::string str_grocery("grocery");
        std::string str_pharmacy("pharmacy");
        std::string str_restaurant("restaurant");
        auto isNotValidChar = [](char c)->bool {return !(isalnum(c) || (c == '_'));};

        for (int i=0; i < len; ++i) {
            if(!isActive[i]) {
                continue;
            }
            if(find_if(code[i].begin(), code[i].end(), isNotValidChar) != code[i].end() || code[i].empty()) {
                continue;
            }
            if(!businessLine[i].compare(str_electronics)) {
                insert_sorted(electronics,code[i]);
                continue;
            }
            if(!businessLine[i].compare(str_grocery)) {
                insert_sorted(grocery,code[i]);
                continue;
            }
            if(!businessLine[i].compare(str_pharmacy)) {
                insert_sorted(pharmacy,code[i]);
                continue;
            }
            if(!businessLine[i].compare(str_restaurant)) {
                insert_sorted(restaurant,code[i]);
                continue;
            }
        }
        copy(electronics.begin(), electronics.end(), back_inserter(ans));
        copy(grocery.begin(), grocery.end(), back_inserter(ans));
        copy(pharmacy.begin(), pharmacy.end(), back_inserter(ans));
        copy(restaurant.begin(), restaurant.end(), back_inserter(ans));

        return ans;
        
    }
};