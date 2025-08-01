class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = Counter(tasks)
        max_heap = [-cnt for cnt in freq.values()]
        heapq.heapify(max_heap)
        q = deque()  # (count, available_time)
        time = 0

        while max_heap or q:
            time += 1

            # Run task
            if max_heap:
                count = heapq.heappop(max_heap)
                if count + 1 < 0:  # still tasks left
                    q.append((count + 1, time + n))

            # Check cooldown queue
            if q and q[0][1] == time:
                heapq.heappush(max_heap, q.popleft()[0])

        return time
