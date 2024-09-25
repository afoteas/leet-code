#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> sumPrefixScoresOne(std::vector<std::string>& words) {
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

    	vector<int> sumPrefixScores(vector<string>& words) {
		int n = words.size();
		vector<pair<string, int>> words2;
		for (int i = 0; i < n; ++i) {
			words2.push_back(make_pair(words[i], i));
		}
		sort(words2.begin(), words2.end());

		vector<int> perm(n);
		for (int i = 0; i < n; ++i) {
			perm[i] = words2[i].second;
		}
		vector<int> commonPrefix(n);

		for (int i = 1; i < n; ++i) {
			string const& w1 = words2[i - 1].first;
			string const& w2 = words2[i].first;
			int l = min(w1.size(), w2.size());
			int p = 0;
			while (p < l && w1[p] == w2[p]) {
				++p;
			}
			commonPrefix[i] = p;
		}

		vector<int> ret(n);
		for (int i = 0; i < n; ++i) {
			int prefix = words2[i].first.size();
			ret[perm[i]] += prefix;
			for (int j = i + 1; j < n; ++j) {
				prefix = min(prefix, commonPrefix[j]);
				if (prefix == 0) {
					break;
				}
				ret[perm[i]] += prefix;
				ret[perm[j]] += prefix;
			}
		}
		return ret;
	}
};