class Solution:
    def eventualSafeNodesSlow(self, graph: List[List[int]]) -> List[int]:
        safeNodes = set()
        unsafe = []
        visited = []
        def hasCircle(gra, i):
            if i not in safeNodes:
                visited.append(i)
            # print(f"visited={visited}")
            # print(f"gra={gra}")
            else:
                return False

            ret = False
            for g in gra:
                if g in safeNodes:
                    # print(f"{g} is safenode")
                    continue
                if g in visited:
                    # print(f"{g} in visited")
                    # unsafe.append(g)
                    return True
                else:
                    ret = hasCircle(graph[g],g) or ret
                    if not ret:
                        safeNodes.add(g)
            return ret

        
        i = 0
        for g in graph:
            visited = []
            # print(f"safeNodes={safeNodes}")

            if not hasCircle(g,i):
                # print(f"{i} does not have circle")
                safeNodes.add(i)
            # else:
                # print(f"{i} has circle")
            i+=1
        return sorted(safeNodes)


    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        res = []
        visited = {}

        def dfs(node):
            if node in visited:
                return visited[node]
            
            visited[node]=True

            for nei in graph[node]:
                if dfs(nei):
                    return True
            
            visited[node]=False

        for i in range(len(graph)):
            if not dfs(i):
                res.append(i)

        return res
        