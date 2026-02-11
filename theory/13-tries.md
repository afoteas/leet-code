# Tries (Prefix Trees)

## Overview
Tree-like data structure for storing strings where each node represents a character. Efficient for prefix-based operations.

## Implementation

### Basic Trie Node
```cpp
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};
```

### Array-based (for lowercase letters)
```cpp
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }
        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};
```

## Common Problems

### Word Search II (Grid + Trie)
```cpp
class Solution {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word;
    };
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->word = word;
        }
        return root;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || node->children.find(c) == node->children.end()) {
            return;
        }
        
        node = node->children[c];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";  // Avoid duplicates
        }
        
        board[i][j] = '#';  // Mark visited
        
        int m = board.size(), n = board[0].size();
        if (i > 0) dfs(board, i - 1, j, node, result);
        if (i < m - 1) dfs(board, i + 1, j, node, result);
        if (j > 0) dfs(board, i, j - 1, node, result);
        if (j < n - 1) dfs(board, i, j + 1, node, result);
        
        board[i][j] = c;  // Restore
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> result;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        
        return result;
    }
};
```

### Replace Words (Dictionary)
```cpp
string replaceWords(vector<string>& dictionary, string sentence) {
    Trie trie;
    for (string& root : dictionary) {
        trie.insert(root);
    }
    
    istringstream iss(sentence);
    string word, result;
    
    while (iss >> word) {
        string prefix;
        TrieNode* node = trie.root;
        
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                break;
            }
            prefix += c;
            node = node->children[c];
            if (node->isEndOfWord) {
                break;
            }
        }
        
        if (!result.empty()) result += " ";
        result += node->isEndOfWord ? prefix : word;
    }
    
    return result;
}
```

### Longest Word in Dictionary
```cpp
string longestWord(vector<string>& words) {
    Trie trie;
    for (string& word : words) {
        trie.insert(word);
    }
    
    string longest;
    
    function<void(TrieNode*, string)> dfs = [&](TrieNode* node, string word) {
        for (auto& [c, child] : node->children) {
            if (child->isEndOfWord) {
                string newWord = word + c;
                if (newWord.length() > longest.length() || 
                    (newWord.length() == longest.length() && newWord < longest)) {
                    longest = newWord;
                }
                dfs(child, newWord);
            }
        }
    };
    
    dfs(trie.root, "");
    return longest;
}
```

### Autocomplete / Suggestion System
```cpp
class AutocompleteSystem {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        map<int, set<string>, greater<int>> sentences;  // frequency -> sentences
    };
    
    TrieNode* root;
    TrieNode* current;
    string prefix;
    unordered_map<string, int> frequency;
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        current = root;
        prefix = "";
        
        for (int i = 0; i < sentences.size(); i++) {
            frequency[sentences[i]] = times[i];
            insert(sentences[i], times[i]);
        }
    }
    
    void insert(string& sentence, int freq) {
        TrieNode* node = root;
        for (char c : sentence) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->sentences[freq].insert(sentence);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            frequency[prefix]++;
            insert(prefix, frequency[prefix]);
            current = root;
            prefix = "";
            return {};
        }
        
        prefix += c;
        
        if (current && current->children.find(c) != current->children.end()) {
            current = current->children[c];
            
            vector<string> result;
            for (auto& [freq, sents] : current->sentences) {
                for (string& s : sents) {
                    result.push_back(s);
                    if (result.size() == 3) return result;
                }
            }
            return result;
        }
        
        current = nullptr;
        return {};
    }
};
```

## When to Use Tries

✅ **Use When:**
- Prefix matching/searching
- Autocomplete features
- Spell checking
- IP routing (longest prefix match)
- Dictionary lookups
- Word games (Boggle, Scrabble)

❌ **Don't Use When:**
- Simple string search (use hash table)
- Suffix matching (use suffix tree)
- Single word lookup (hash table is simpler)
- Limited memory (tries can be space-intensive)

## Common Patterns

### 1. Build Trie + DFS
Used in Word Search II, Boggle

### 2. Trie + Greedy
Used in Replace Words, adding prefixes

### 3. Trie with Additional Data
Store frequency, count, or other info in nodes

## Time Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Insert | O(L) | O(L) |
| Search | O(L) | O(1) |
| Prefix Search | O(L) | O(1) |
| Delete | O(L) | O(1) |

*L = length of word/prefix*

## Space Complexity
- **Worst case:** O(ALPHABET_SIZE × N × L)
- **Average case:** Better due to shared prefixes

## Common Problems
- Implement Trie (LeetCode #208)
- Word Search II (LeetCode #212)
- Design Add and Search Words Data Structure (LeetCode #211)
- Replace Words (LeetCode #648)
- Longest Word in Dictionary (LeetCode #720)
- Design Search Autocomplete System (LeetCode #642)

## Tips
- Array-based children faster for fixed alphabet
- HashMap for variable characters (Unicode, etc.)
- Store complete word at end node for easier retrieval
- Consider space-time tradeoff
- DFS on trie for word collection
- Can store frequency/priority for autocomplete

[← Back to README](README.md)
