class Solution {
public:
    string intToRoman(int num) {
        string returnStr = "";
        vector<pair<string,int>> values ={{"M",1000}, {"CM",900}, {"D",500}, {"CD",400}, {"C",100}, {"XC",90},
         {"L",50}, {"XL",40}, {"X",10}, {"IX",9},{"V",5}, {"IV",4}, {"I",1}};
         for(auto &v:values) {
            int count = num/v.second;
            num -= v.second*count;
            for(int i=0; i<count; i++) {
                returnStr += v.first;
            }
         }
         return returnStr;
    }
};


    // def intToRoman(self, num: int) -> str:
    //     returnStr = ""
    //     values = {"M":1000, "CM":900, "D":500, "CD":400, "C":100, "XC":90,
    //      "L":50, "XL":40, "X":10, "IX":9, "V":5, "IV":4, "I":1}
    //     for number in values:
    //         count = num // values[number]
    //         num = num - values[number]*count
    //         returnStr += number*count
    //     return returnStr