class Trie {
public:
    unordered_map<char,Trie> trie;
    bool end = false;
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* curr = this;
        for (auto &c: word) {
            if (curr->trie.find(c) == curr->trie.end()) {
                curr->trie[c]=Trie();
            }
            curr = &curr->trie[c];
        }
        curr->end = true;
        
    }
    
    bool search(string word) {
        Trie* curr = this;
        for (auto &c: word) {
            if (curr->trie.find(c) == curr->trie.end()) {
                return false;
            }
            curr = &curr->trie[c];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for (auto &c: prefix) {
            if (curr->trie.find(c) == curr->trie.end()) {
                return false;
            }
            curr = &curr->trie[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */