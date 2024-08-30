class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
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

        vector<int> path = {0};
        dfs(0,path);
        return ret;
    }
};

    // def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
    //     self.ret = []
    //     def dfs(u: int, t: int, path: List[int]):
    //         if u == t:
    //             self.ret.append(path)
    //         for v in graph[u]:
    //             dfs(v, t, path + [v])
    //     dfs(0, len(graph) - 1, [0])
    //     return self.ret