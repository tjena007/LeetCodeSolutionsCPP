class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        for num in nums:
            d[num] = d.get(num,0) + 1
        
        h = []
        heap = [(-value, key) for key, value in d.items()]
        heapq.heapify(heap)
        
        ans = [heapq.heappop(heap)[1] for _ in range(min(k, len(heap)))]

        return ans

        