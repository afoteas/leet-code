#include <algorithm>

using namespace std;

class Solution {
public:


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
                    electronics.insert(upper_bound(electronics.begin(), electronics.end(), code[i]), code[i]);
                    break;
                case Line::Grocery:     
                    grocery.insert(upper_bound(grocery.begin(), grocery.end(), code[i]), code[i]);
                    break;
                case Line::Pharmacy:    
                    pharmacy.insert(upper_bound(pharmacy.begin(), pharmacy.end(), code[i]), code[i]);
                    break;
                case Line::Restaurant:  
                    restaurant.insert(upper_bound(restaurant.begin(), restaurant.end(), code[i]), code[i]);
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

        return ans;
    }

};