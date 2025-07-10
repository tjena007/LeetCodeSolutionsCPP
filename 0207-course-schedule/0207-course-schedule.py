class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        # build the adjancy list

        graph = defaultdict(list)
        in_degree = [0] * numCourses

        # Step 1: Build the graph and in-degree array
        for dest,src in prerequisites:
            graph[src].append(dest)
            in_degree[dest] += 1
        
        # Step 2: Queue for all courses with no prerequisites
        queue = deque([i for i in range(numCourses) if in_degree[i] == 0])
        
        #bfs
        completed = 0
        while queue:
            course = queue.popleft()
            completed += 1

            for neighbor in graph[course]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)
        

        return completed == numCourses


        
