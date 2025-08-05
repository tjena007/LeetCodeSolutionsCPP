class MedianFinder:

    def __init__(self):
        self.minHeap = []  # higher half
        self.maxHeap = []  # lower half (store as negative values)

    def addNum(self, num: int) -> None:
        # Step 1: Add to maxHeap (as negative)
        heapq.heappush(self.maxHeap, -num)

        # Step 2: Balance order (largest of maxHeap to minHeap)
        if self.maxHeap and self.minHeap and (-self.maxHeap[0] > self.minHeap[0]):
            val = -heapq.heappop(self.maxHeap)
            heapq.heappush(self.minHeap, val)

        # Step 3: Balance sizes
        if len(self.maxHeap) > len(self.minHeap) + 1:
            val = -heapq.heappop(self.maxHeap)
            heapq.heappush(self.minHeap, val)

        if len(self.minHeap) > len(self.maxHeap) + 1:
            val = heapq.heappop(self.minHeap)
            heapq.heappush(self.maxHeap, -val)

    def findMedian(self) -> float:
        if len(self.maxHeap) == len(self.minHeap):
            return (-self.maxHeap[0] + self.minHeap[0]) / 2
        elif len(self.maxHeap) > len(self.minHeap):
            return -self.maxHeap[0]
        else:
            return self.minHeap[0]