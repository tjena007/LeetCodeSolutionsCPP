class MedianFinder:
    #introduce two heaps, min and max
    #count difference in both should not be greater than 1
    #put in any one, then move the element to other heap if needed
    # for median, if count is same, then both top element /2, or return top from which count is higher
    def __init__(self):
        self.left,self.right = [],[]

    def addNum(self, num: int) -> None:
        if self.right and num > self.right[0]:
            heapq.heappush(self.right,num)
        else:
            heapq.heappush(self.left,-1*num)
        
        if len(self.left) > len(self.right) + 1:
            val = -1 * heapq.heappop(self.left)
            heapq.heappush(self.right,val)
        if len(self.right) > len(self.left) + 1:
            val = heapq.heappop(self.right)
            heapq.heappush(self.left,-1*val)

    def findMedian(self) -> float:
        if len(self.left) > len(self.right):
            return -1*self.left[0]
        elif len(self.right) > len(self.left):
            return self.right[0]
        return (-1*self.left[0] + self.right[0])/2.0
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()