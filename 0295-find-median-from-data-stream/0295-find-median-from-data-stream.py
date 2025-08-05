import heapq

class MedianFinder:

    def __init__(self):
        self.minHeap = []  # stores larger half
        self.maxHeap = []  # stores smaller half (as negative numbers)

    def addNum(self, num: int) -> None:
        # Step 1: Push to maxHeap (negate to simulate max behavior)
        heapq.heappush(self.maxHeap, -num)

        # Step 2: Move largest of maxHeap to minHeap
        heapq.heappush(self.minHeap, -heapq.heappop(self.maxHeap))

        # Step 3: Balance sizes (maxHeap can have 1 extra element)
        if len(self.minHeap) > len(self.maxHeap):
            heapq.heappush(self.maxHeap, -heapq.heappop(self.minHeap))

    def findMedian(self) -> float:
        # Odd count → top of maxHeap
        if len(self.maxHeap) > len(self.minHeap):
            return -self.maxHeap[0]
        # Even count → average of tops
        return (-self.maxHeap[0] + self.minHeap[0]) / 2
