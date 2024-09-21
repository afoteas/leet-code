class Solution {
public:
    vector<int> lexicalOrder(int n) {
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
};