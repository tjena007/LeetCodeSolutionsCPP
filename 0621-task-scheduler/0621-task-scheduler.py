class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        d = {}
        heap = []
        q = deque()

        for task in tasks:
            d[task] = d.get(task,0) + 1
        
        for k,v in d.items():
            heapq.heappush(heap,(-v))
        
        time = 0
        while heap or q:
            time += 1
            if heap:
                count = heapq.heappop(heap)
                if count + 1 < 0:
                    q.append([count+1,time + n])

            if q and time == q[0][1]:
                heapq.heappush(heap,q.popleft()[0])

        return time


