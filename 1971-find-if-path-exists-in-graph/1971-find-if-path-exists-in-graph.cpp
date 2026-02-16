class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n,false);
        for(auto& e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        queue<int> q;

        q.push(source);
        while(!q.empty()){
            int c = q.front();
            q.pop();
            visited[c] = true;
            if(c == destination) return true;
            for(auto& n: graph[c]) {
                if(!visited[n]) {
                    q.push(n);
                }
            }
        }

        return false;
    }
};