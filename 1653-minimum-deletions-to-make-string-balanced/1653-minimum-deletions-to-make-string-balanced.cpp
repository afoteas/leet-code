class Solution {
public:


    int minimumDeletions(string s) {
        int potentialNumberOfDeletion = 0;
        int minimumDeletion = 0;

        for (int i = 0; i <= s.size() - 1; i++)
            if (s[i] == 'b') {
                potentialNumberOfDeletion++;
            }
            else {
                if (potentialNumberOfDeletion > 0) {
                    potentialNumberOfDeletion--;
                    minimumDeletion++;
                }
            }
        
        return minimumDeletion;
    }

    int minimumDeletionsMine(string s) {
        vector<int> a(s.size()+1);
        vector<int> b(s.size()+1);
        int ret = s.size();
        for(int i=1; i<s.size(); ++i) {
            b[i] = (s[i-1] == 'b') ? b[i-1]+1: b[i-1];
        }
        for(int i=s.size()-1; i>0; --i) {
            a[i-1] = (s[i] == 'a') ? a[i]+1: a[i];
        }
        // cout<<"a: ";
        // for(int i=0; i<a.size()-1; ++i) {
        //     cout<< a[i] << " ";
        // }
        // cout<<"\nb: ";
        // for(int i=0; i<a.size()-1; ++i) {
        //     cout<< b[i] << " ";
        // }
        for(int i=0; i<s.size(); ++i) {
            ret = min(ret, a[i]+b[i]);
        }
        
        return ret;
    }
};