class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int t = int(target);
        int minDist = 256;
        char ans = letters[0];
        for(int i = 0; i < letters.size(); ++i) {
            int d = int(letters[i])-int(target);
            if(d>0 && d<minDist) {
                minDist = d;
                ans = letters[i];
            }
        }
        return ans;
    }
};