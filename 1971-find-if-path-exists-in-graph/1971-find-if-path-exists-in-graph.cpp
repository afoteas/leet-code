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
        visited[source] = true;
        while(!q.empty()){
            int c = q.front();
            q.pop();
            // visited[c] = true;
            if(c == destination) return true;
            for(auto& n: graph[c]) {
                if(!visited[n]) {
                    q.push(n);
                    visited[n] = true;
                }
            }
        }

        return false;
    }


    // bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    //     vector<vector<int>> adj(n);

    //     for(int i =0; i<edges.size(); i++)
    //     {
    //         int u = edges[i][0];
    //         int v = edges[i][1];

    //         adj[u].push_back(v);
    //         adj[v].push_back(u);

    //     }
    //     vector<bool>visited(n,false);
    //     queue<int>q;
    //     q.push(source);
    //     visited[source] = true;

    //     while(!q.empty())
    //     {
    //       int node = q.front();
    //       q.pop();

    //       for(auto it:adj[node])
    //       {
    //         if(!visited[it])
    //         {
    //             q.push(it);
    //             visited[it] = true;
    //         }
    //       }
    //         if(node == destination)
    //       {
    //         return true;
    //       }
    //     }

    //     return false;

    // }
};