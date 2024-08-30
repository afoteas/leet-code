class Solution {
public:
    vector<vector<int>> allPathsSourceTargetDfs(vector<vector<int>>& graph) {
        int t = graph.size()-1;
        vector<vector<int>> ret;
        function<void(int, vector<int>)> dfs = [&](int u, vector<int> path) { 
            if(u==t) {
                ret.push_back(path);
            }
            for(int v:graph[u]) {
                path.push_back(v);
                dfs(v, path);
                path.pop_back();
            }
        };
        dfs(0,{0});
        return ret;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int size = graph.size()-1;
        vector<vector<int>> ret;
        deque<vector<int>> bfs(1,vector(1,0));
        while(!bfs.empty()) {
            vector<int> temp = bfs.front();
            bfs.pop_front();
            if(temp.back() == size) {
                ret.push_back(temp);
            }
            for(auto& nei:graph[temp.back()]) {
                temp.push_back(nei);
                bfs.push_back(temp);
                temp.pop_back();
            }
            
        }
        return ret;
    }
};

            // for nei in graph[path[-1]]:
            //     q.insert(0,path + [nei])

