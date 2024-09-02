#include <limits>
#include <vector>
#include <map>
#include <queue>
#include <limits>
#include <cmath>

class Solution {
public:

    double dijkstra(map<int,vector<pair<int,double>>>& graph, int source, int destination) {
        map<int, double> distance;
        for (const auto& node : graph) {
            distance[node.first] = numeric_limits<double>::infinity();
        }
        distance[source] = 0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
        pq.push({0, source});
        while (!pq.empty()) {
            pair<double, int> top = pq.top();
            pq.pop();

            double dist = top.first;
            int current = top.second;

            if (current == destination) {
                return dist;
            }
            for (const auto& pair : graph[current]) {
                int neighbor = pair.first;
                double weight = pair.second;
                
                double newDistance = dist + weight;
                if (newDistance < distance[neighbor]) {
                    distance[neighbor] = newDistance;
                    pq.push({newDistance, neighbor});
                }
            }
        }
        return -1;

    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        map<int,vector<pair<int,double>>> graph;
        for (size_t i = 0; i < edges.size(); ++i) {
            int s = edges[i][0];
            int d = edges[i][1];
            double logVal = (succProb[i] > 0) ? -log(succProb[i]) : numeric_limits<double>::infinity();
            graph[s].push_back({d, logVal});
            graph[d].push_back({s, logVal});
        }

        double minPath = dijkstra(graph, start_node, end_node);
        if (minPath == -1) {
            return 0;
        } else {
            return exp(-minPath);
        }
        
    }
};
