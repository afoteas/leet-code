class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gs=g.size();
        int ss=s.size();
        int gc=0;
        int sc=0;
        while(gc<gs && sc < ss) {
            if(g[gc]<=s[sc++]) ++gc;
        }
        return gc;
        
    }
};