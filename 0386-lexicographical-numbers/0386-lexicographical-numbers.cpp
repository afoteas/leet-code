class Solution {
public:
    vector<int> lexicalOrderSlow(int n) {
        set<string> orderedSet;
        vector<int> lexicalOrderedList;

        for(int i = 1; i<n+1;i++) {
            orderedSet.insert(std::to_string(i));
        }
        for (const std::string& numStr : orderedSet) {
            lexicalOrderedList.push_back(std::stoi(numStr));
        }
        return lexicalOrderedList;
    }


    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        function<void(int)> f = [&ans, n, &f] (int i) mutable
        {
            if (i>n) return;
            ans.push_back(i);
            for(int j=0; j<=9; j++){
                int x=10*i+j;
                if (x>n) break;
                f(x);
            }
        };
        ans.reserve(n);
        for(int i=1; i<=9&& i<=n; i++)
            f(i);
        return ans;
    }
};

