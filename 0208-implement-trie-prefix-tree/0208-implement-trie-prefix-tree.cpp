class Trie {
public:
    unordered_map<char,Trie> trie;
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
        curr->trie['#']=Trie();
        
    }
    
    bool search(string word) {
        Trie* curr = this;
        for (auto &c: word) {
            if (curr->trie.find(c) == curr->trie.end()) {
                return false;
            }
            curr = &curr->trie[c];
        }
        if (curr->trie.find('#') == curr->trie.end()) {
            return false;
        } else {
            return true;
        }
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


    //  def insert(self, word: str) -> None:
    //     t = self.trie
    //     for w in word:
    //         if w not in t:
    //             t[w] = {}
    //         t = t[w]
    //     t['#'] = True

    // def search(self, word: str) -> bool:
    //     t = self.trie
    //     for w in word:
    //         if w not in t:
    //             return False
    //         t = t[w]
    //     return True if '#' in t else False

    // def startsWith(self, prefix: str) -> bool:
    //     t = self.trie
    //     for w in prefix:
    //         if w not in t:
    //             return False
    //         t = t[w]
    //     return True