class Solution {
public:
    int minReorderSlow(int n, vector<vector<int>>& connections) {
        unsigned s = 0;
        std::unordered_map<int, std::vector<std::vector<int>>> adjacent;
        for (const auto& edge : connections) {
            adjacent[edge[0]].push_back(edge);
            adjacent[edge[1]].push_back(edge);
        }

        std::list<int> curr{0};
        std::set<int> seen;
        while (!curr.empty()){
            for(const auto& node: curr) {
                for(const auto& edge: adjacent[node]) {
                    if (!seen.contains(edge[0]) && edge[1] == node) {
                        curr.push_back(edge[0]);
                    } else if (!seen.contains(edge[1]) && edge[0] == node) {
                        ++s;
                        curr.push_back(edge[1]);
                    }
                }
                seen.insert(node);
            }
            curr.pop_front();
        }
        return s;
    }

    int minReorderBfs(int n, vector<vector<int>>& connections) {
        int s = 0;
        
        // Create map mapping vertices to their adjacent edges
        unordered_map<int, vector<vector<int>>> adj;
        for (const auto& c : connections) {
            adj[c[0]].push_back(c);
            adj[c[1]].push_back(c);
        }
        
        // Run the search
        set<int> curr = {0};
        set<int> seen = {0};
        while (!curr.empty()) {
            set<int> nxt;  // Will contain neighbors of `curr` not in `seen`
            for (int v : curr) {
                for (auto& e : adj[v]) {
                    if (e[0] != v && seen.find(e[0]) == seen.end()) {
                        // Pointing the 'right' direction
                        nxt.insert(e[0]);
                    }
                    else if (e[0] == v && seen.find(e[1]) == seen.end()) {
                        // Pointing the 'wrong' direction
                        nxt.insert(e[1]);
                        s++;
                    }
                }
            }
            curr = nxt;
            seen.insert(nxt.begin(), nxt.end());
        }
        
        return s;
    }

    int count = 0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
        for (auto& [neighbor, sign] : adj[node]) {
            if (neighbor != parent) {
                count += sign;
                dfs(neighbor, node, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        dfs(0, -1, adj);
        return count;
    }
};

    // def minReorder(self, n: int, connections: List[List[int]]) -> int:
    //     s = 0
    //     # create dictionary mapping vertices to their adjacent edges
    //     adj = defaultdict(list)
    //     for c in connections:
    //         adj[c[0]].append(c)
    //         adj[c[1]].append(c)

    //     # run the search
    //     curr = {0}
    //     seen = set()
    //     while curr:
    //         next_curr = set()
    //         for v in curr:
    //             for e in adj[v]:
    //                 if e[0] not in seen and e[1] == v:
    //                     # pointing the 'right' direction
    //                     next_curr.add(e[0])
    //                 elif e[0] == v and e[1] not in seen:
    //                     # pointing the 'wrong' direction
    //                     next_curr.add(e[1])
    //                     s += 1
    //             seen.add(v)
    //         curr = next_curr
    //     return s