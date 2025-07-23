class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = defaultdict(list)
        for u, v, price in flights:
            graph[u].append((v, price))
        
        # (cost, stops, node)
        minHeap = [(0, 0, src)]
        # best[node][stops] = min cost
        best = dict()

        while minHeap:
            cost, stops, node = heapq.heappop(minHeap)

            if node == dst:
                return cost  # Cheapest way to reach dst

            if stops > k:
                continue  # exceeded stop limit

            for nei, price in graph[node]:
                newCost = cost + price
                # Only push if it's better or first time
                if (nei, stops) not in best or best[(nei, stops)] > newCost:
                    best[(nei, stops)] = newCost
                    heapq.heappush(minHeap, (newCost, stops + 1, nei))

        return -1