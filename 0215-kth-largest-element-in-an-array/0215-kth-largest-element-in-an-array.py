class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        arr = []
        for num in nums:
            heapq.heappush(arr,-1*num)
        
        ans = float(inf)
        while k > 0:
            ans = heapq.heappop(arr)
            k -= 1
        return -1 * ans