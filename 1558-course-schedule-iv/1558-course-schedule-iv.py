class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        graph = defaultdict(list)

        for u,v in prerequisites:
            graph[u].append(v)
        
        cache = {}
        def dfs(node):
            if node in cache:
                return cache[node]
            
            reachable = set()
            for nei in graph[node]:
                reachable.add(nei)
                reachable |= dfs(nei)  # union with neighbor's reachable set
            
            cache[node] = reachable
            return reachable
            

        path = {}
        for i in range(numCourses):
            path[i] = dfs(i)
        
        ans = []
        for i,j in queries:
            if j in path[i]:
                ans.append(True)
            else:
                ans.append(False)
        

        return ans

        
        
