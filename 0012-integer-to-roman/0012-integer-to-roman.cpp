class Solution {
public:
    string intToRoman(int num) {
        string returnStr = "";
        vector<pair<string,int>> values ={{"M",1000}, {"CM",900}, {"D",500}, {"CD",400}, {"C",100}, {"XC",90},
         {"L",50}, {"XL",40}, {"X",10}, {"IX",9},{"V",5}, {"IV",4}, {"I",1}};
         for(auto &v:values) {
            int count = num/v.second;
            num -= v.second*count;
            while (count--) {
                returnStr += v.first;
            }
         }
         return returnStr;
    }
};
