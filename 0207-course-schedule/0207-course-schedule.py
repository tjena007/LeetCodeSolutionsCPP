class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        # build the adjancy list

        graph = defaultdict(list)

        for dest,src in prerequisites:
            graph[src].append(dest)
        
        visited = [0] * numCourses

        # apply dfs
        def dfs(course):
            if visited[course] == 1:
                return False
            if visited[course] == 2:
                return True
        

            visited[course] = 1
            for neighbor in graph[course]:
                if not dfs(neighbor):
                    return False
            

            visited[course] = 2 #if we reach this point, means no cycle after this node since we checked all the paths
            return True
        
        for i in range(numCourses):
            if not dfs(i):
                return False
        
        return True
