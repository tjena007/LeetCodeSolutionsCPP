class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = defaultdict(list)

        for u, v, t in times:
            graph[u].append([v, t])

        minHeap = [(0, k)]
        visited = set()
        ans = 0

        while minHeap:
            time, node = heapq.heappop(minHeap)
            if node in visited:
                continue

            visited.add(node)
            ans = max(ans, time)

            for nei, wt in graph[node]:
                if nei not in visited:
                    heapq.heappush(minHeap, (time + wt, nei))

        return ans if len(visited) == n else -1
