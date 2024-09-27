
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int l = citations.size();
        int lt = l-1;
        while(lt>=0) {
            if (citations[lt] > l - lt) { 
                lt--;
            }
            else if (citations[lt]== l-lt) {
                return l-lt;
            } 
            else {
                return l - lt - 1;
            }
        }

        return min(l,citations[0]);  
    }
};




// citations.sort()
// l = len(citations)
// lt = l-1
// while lt >= 0:
//     if citations[lt] > l-lt:
//         lt -=1
//     elif citations[lt] == l-lt:
//         return l-lt
//     else:
//         return l-lt-1
// return min(len(citations),citations[0])        