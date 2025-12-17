// class Solution {
// public:
//     vector<bool> prefixesDivBy5(vector<int>& nums) {
//         vector<bool> ret {};
//         int current = 0;
//         int power = 0;
//         for(auto const bit: nums) {
//             cout << "power: " << power << endl;
//             cout << "current: " << current << endl;
//             cout << "bit: " << bit << endl;
//             if(bit==1) {
//                 current += 1<<power;
//             }
//             if (current % 5) {
//                 ret.push_back(false);
//             } else {
//                 ret.push_back(true);
//             }
//             power++;
//         }
//         return ret;
//     }
// };


#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ret;
        int current = 0;
        for (auto bit : nums) {
            current = ((current << 1) | bit) % 5;
            ret.push_back(current == 0);
        }
        return ret;
    }
};