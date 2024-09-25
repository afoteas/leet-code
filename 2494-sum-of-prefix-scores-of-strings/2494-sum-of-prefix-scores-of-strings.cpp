#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
        // Trie node definition
        class TrieNode {
        public:
            int count;
            std::unordered_map<char, TrieNode*> children;
            TrieNode() : count(0) {}
        };
        
        // Root of the Trie
        TrieNode* root = new TrieNode();
        
        // Build the Trie and count prefix occurrences
        for (const std::string& word : words) {
            TrieNode* curr = root;
            for (char c : word) {
                if (curr->children.find(c) == curr->children.end()) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
                curr->count += 1;
            }
        }
        
        // Calculate prefix scores for each word
        std::vector<int> prefixCounts;
        for (const std::string& word : words) {
            int prefixCount = 0;
            TrieNode* curr = root;
            for (char c : word) {
                curr = curr->children[c];
                prefixCount += curr->count;
            }
            prefixCounts.push_back(prefixCount);
        }
        
        // Cleanup (optional)
        // You would typically need to clean up the allocated Trie nodes here.
        // For now, we'll skip the cleanup for simplicity.

        return prefixCounts;
    }
};