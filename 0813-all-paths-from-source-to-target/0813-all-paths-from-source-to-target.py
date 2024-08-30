class Solution:
    def allPathsSourceTarget_29_30(self, graph: List[List[int]]) -> List[List[int]]:
        destination = len(graph)
        routes = defaultdict(list)
        routes[0] = [[0]]
        i = 0
        for nodes in graph:
            print(f"i={i}, nodes={nodes}")
            print(routes)
            for node in nodes:
                print(f'node={node}, routes[{i}]={routes[i]}')
                for route in routes[i]:
                    temp = list(route)
                    temp.append(node)
                    routes[node].append(temp)
            i+=1

        return routes[destination-1]


    def allPathsSourceTargetDfs(self, graph: List[List[int]]) -> List[List[int]]:
        def dfs(u: int, t: int, path: List[int]) -> Generator:
            if u == t:
                yield path

            for v in graph[u]:
                yield from dfs(v, t, path + [v])

        graph = {
            u: neighbours
            for u, neighbours in enumerate(graph)
        }
        return dfs(0, len(graph) - 1, [0])

    def allPathsSourceTargetDeque(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        # Instead of nodes append whole path to the queue
        def bfs(src, dst, res):
            q = deque([[src]])
            while q:
                path = q.popleft()
                print(path)
                if path[-1] == n-1:
                    res.append(path)
                for nei in graph[path[-1]]:
                    q.append(path + [nei])
        
        res = []
        bfs(0, n-1, res)
        return res


    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        res = []
        q = [[0]]
        while q:
            path = q.pop()
            if path[-1] == n-1:
                res.append(path)
            for nei in graph[path[-1]]:
                q.insert(0,path + [nei])
        return res

        