const int N = 100001;
int root[N];
vector<int> adj[N];

class Solution {
public:
    bitset<N> viz = 0;
    vector<set<int>> comp;

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // build_adj moved inside
        auto build_adj = [&](int c, vector<vector<int>>& connections) {
            for (int i = 1; i <= c; i++) adj[i].clear();
            for (auto& e : connections) {
                int u = e[0], v = e[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        };

        // dfs moved inside
        auto dfs = [&](auto&& self, int i0, int i) -> void {
            root[i] = i0;
            comp[i0].insert(i);
            viz[i] = 1;
            for (int j : adj[i]) {
                if (!viz[j]) self(self, i0, j);  // \U0001f448 recursive call
            }
        };

        // main logic
        build_adj(c, connections);
        comp.resize(c + 1);

        for (int i = 1; i <= c; i++) {
            if (!viz[i]) dfs(dfs, i, i);
        }

        vector<int> ans;
        for (auto& q : queries) {
            const int t = q[0], x = q[1], rx = root[x];
            auto& C = comp[rx];
            if (t == 2)
                C.erase(x);
            else {
                if (C.empty()) ans.push_back(-1);
                else if (C.count(x)) ans.push_back(x);
                else ans.push_back(*C.begin());
            }
        }

        return ans;
    }
};