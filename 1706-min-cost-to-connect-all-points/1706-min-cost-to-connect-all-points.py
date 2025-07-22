class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        N = len(points)

        graph = defaultdict(list)

        for i in range(N):
            x1,y1 = points[i]
            for j in range(i+1,N):
                x2,y2 = points[j]
                dist = abs(x2-x1) + abs(y2-y1)
                graph[i].append([dist,j])
                graph[j].append([dist,i])
        

        ans = 0
        visited = set()
        minHeap = [[0,0]]
        while len(visited) < N:
            cost,i = heapq.heappop(minHeap)
            if i in visited:
                continue
            
            visited.add(i)
            ans += cost
            for neiCost,nei in graph[i]:
                if nei not in visited:
                    heapq.heappush(minHeap,[neiCost,nei])
        
        return ans