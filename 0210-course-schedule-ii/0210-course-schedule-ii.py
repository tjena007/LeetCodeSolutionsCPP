class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        in_degree = [0] * numCourses

        for dest,src in prerequisites:
            graph[src].append(dest)
            in_degree[dest] += 1
        

        queue = deque([i for i in range(numCourses) if in_degree[i]==0])

        ans = []
        while queue:
            node = queue.popleft()
            ans.append(node)

            for neighbors in graph[node]:
                in_degree[neighbors] -= 1
                if in_degree[neighbors] == 0:
                    queue.append(neighbors)
        
        if len(ans) == numCourses:
            return ans
        
        return []

