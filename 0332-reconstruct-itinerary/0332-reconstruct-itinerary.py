class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = defaultdict(list)
        
        # Step 1: Build graph using min-heaps to maintain lexical order
        for src, dest in tickets:
            heapq.heappush(graph[src], dest)
        
        res = []

        # Step 2: DFS traversal
        def dfs(node):
            while graph[node]:
                next_dest = heapq.heappop(graph[node])
                dfs(next_dest)
            res.append(node)  # post-order append

        # Step 3: Start DFS from JFK
        dfs("JFK")

        # Step 4: Reverse result because we built it backward
        return res[::-1]