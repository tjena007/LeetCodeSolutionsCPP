class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = [-1 * num for num in stones]
        heapq.heapify(heap)

        while heap:
            #first 2 ele
            stone1 = -1 * heapq.heappop(heap)
            if not heap:
                return stone1
            stone2 = -1 * heapq.heappop(heap)

            if stone1 - stone2 > 0:
                heapq.heappush(heap,-1*(stone1 - stone2))
            
        return 0