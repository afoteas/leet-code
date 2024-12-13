class Solution {
public:
    string gcdOfStringsMem(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        function<int(int, int)> gcd = [](int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        };
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);        
    }

    string gcdOfStrings(string str1, string str2) {
        return str1+str2==str2+str1?str2.substr(0,gcd(str1.length(),str2.length())):"";
    }
};
