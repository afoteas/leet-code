class Solution {
public:


    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        unordered_map<int, unordered_set<int>> neighbours;
        for (auto& edge : edges) {
            neighbours[edge[0]].insert(edge[1]);
            neighbours[edge[1]].insert(edge[0]);
        }

        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (neighbours[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        int remaining = n;
        while (remaining > 2) {
            remaining -= leaves.size();
            vector<int> newLeaves;
            for (int leaf : leaves) {
                int neighbor = *neighbours[leaf].begin();
                neighbours[neighbor].erase(leaf);
                if (neighbours[neighbor].size() == 1) {
                    newLeaves.push_back(neighbor);
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }

    vector<int> findMinHeightTreesN2(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> neighbours;
        vector<int> ret = {};
        for (auto& edge: edges) {
            neighbours[edge[0]].insert(edge[1]);
            neighbours[edge[1]].insert(edge[0]);
        }
        // cout<<"neighbours:"<<endl;
        // for(auto& d:neighbours) {
        //     cout<<d.first<<": ";
        //     for(auto&c:d.second) {
        //         cout<<c<<" ";
        //     }
        //     cout<<endl;
        // }
        map<int,vector<int>> depthMap;
        for(int i = 0; i < n; i++) {
            int levelSize = 0;
            int level=0;
            queue<int> q;
            unordered_set<int> visited;

            q.push(i);
            while(!q.empty()) {
                levelSize = q.size();
                ++level;
                for(int j=0; j <levelSize; ++j) {
                    int cur = q.front();
                    visited.insert(cur);
                    q.pop();
                    for(auto& neighbour: neighbours[cur]) {
                        if(!visited.contains(neighbour)){
                            q.push(neighbour);
                        }
                    }
                }
            }
            depthMap[level].push_back(i);
        }
        // cout<<"DepthMap:"<<endl;
        // for(auto& d:depthMap) {
        //     cout<<d.first<<": ";
        //     for(auto&c:d.second) {
        //         cout<<c<<" ";
        //     }
        //     cout<<endl;
        // }
        return depthMap.begin()->second;
    }
};