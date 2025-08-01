class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []

        for x,y in points:
            distance = math.sqrt(x**2 + y**2)
            heapq.heappush(heap,(distance,x,y))
        

        ans = []
        c = 0
        while heap and c < k:
            d,x,y = heapq.heappop(heap)
            ans.append([x,y])
            c += 1
        
        return ans
