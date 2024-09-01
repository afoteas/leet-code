import heapq

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        def dijkstra(graph, source, destination):
            distance = {node: float('inf') for node in graph}
            distance[source] = 0
            pq = [(0, source)]

            while pq:
                dist, current = heapq.heappop(pq)

                if current == destination:
                    return dist

                for neighbor, weight in graph[current].items():
                    new_distance = dist + weight

                    if new_distance < distance[neighbor]:
                        distance[neighbor] = new_distance
                        heapq.heappush(pq, (new_distance, neighbor))

            return -1
        
        logSucProb = [-log(prob) if prob > 0 else float('inf') for prob in succProb]
        graph = defaultdict(dict)
        
        for i, (s, d) in enumerate(edges):
            graph[s][d] = logSucProb[i]
            graph[d][s] = logSucProb[i]  # Assuming edges are bidirectional
        
        minPath = dijkstra(graph, start_node, end_node)
        if minPath == -1:
            return 0
        else:
            return exp(-minPath)
        