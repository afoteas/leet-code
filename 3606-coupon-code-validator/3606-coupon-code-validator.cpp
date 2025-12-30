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
    vector<string> validateCouponsMine(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
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


    vector<string> validateCouponsSlowChat(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
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


    enum class Line { Electronics, Grocery, Pharmacy, Restaurant, Invalid };

    Line classify(const string& s) {
        if (s == "electronics") return Line::Electronics;
        if (s == "grocery")     return Line::Grocery;
        if (s == "pharmacy")    return Line::Pharmacy;
        if (s == "restaurant")  return Line::Restaurant;
        return Line::Invalid;
    }

    vector<string> validateCoupons(
        vector<string>& code,
        vector<string>& businessLine,
        vector<bool>& isActive
    ) {
        vector<string> electronics, grocery, pharmacy, restaurant;
        vector<string> ans;

        auto isValidCode = [](const string& s) {
            return !s.empty() && all_of(s.begin(),s.end(), [](char c) {return isalnum(static_cast<unsigned char>(c)) || c == '_';});
        };

        for (size_t i = 0; i < code.size(); ++i) {
            if (!isActive[i] || !isValidCode(code[i])) continue;

            switch (classify(businessLine[i])) {
                case Line::Electronics: 
                    insert_sorted(electronics, code[i]); 
                    break;
                case Line::Grocery:     
                    insert_sorted(grocery, code[i]); 
                    break;
                case Line::Pharmacy:    
                    insert_sorted(pharmacy, code[i]); 
                    break;
                case Line::Restaurant:  
                    insert_sorted(restaurant, code[i]); 
                    break;
                default: 
                    break;
            }
        }
        ans.reserve(electronics.size() + grocery.size() + pharmacy.size() + restaurant.size());
        move(electronics.begin(), electronics.end(), back_inserter(ans));
        move(grocery.begin(), grocery.end(), back_inserter(ans));
        move(pharmacy.begin(), pharmacy.end(), back_inserter(ans));
        move(restaurant.begin(), restaurant.end(), back_inserter(ans));
        // ans.insert(ans.end(), electronics.begin(), electronics.end());
        // ans.insert(ans.end(), grocery.begin(), grocery.end());
        // ans.insert(ans.end(), pharmacy.begin(), pharmacy.end());
        // ans.insert(ans.end(), restaurant.begin(), restaurant.end());

        return ans;
    }

};