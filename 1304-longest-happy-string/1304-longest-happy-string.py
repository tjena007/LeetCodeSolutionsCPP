import heapq

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        ans = ""
        heap = []

        # Push only non-zero counts
        if a: heapq.heappush(heap, (-a, 'a'))
        if b: heapq.heappush(heap, (-b, 'b'))
        if c: heapq.heappush(heap, (-c, 'c'))

        currCount = 0
        currVar = ''

        while heap:
            count, char = heapq.heappop(heap)

            # Case 1: Can't use this char (would form triple)
            if currCount == 2 and char == currVar:
                if heap:
                    count2, char2 = heapq.heappop(heap)
                    ans += char2
                    currVar = char2
                    currCount = 1  # reset for new char

                    # Push back updated count2
                    if count2 + 1 < 0:
                        heapq.heappush(heap, (count2 + 1, char2))
                    
                    # Push the skipped char back
                    heapq.heappush(heap, (count, char))
                else:
                    # No alternative char → end
                    return ans
            else:
                # Case 2: Safe to use this char
                ans += char
                if char == currVar:
                    currCount += 1
                else:
                    currVar = char
                    currCount = 1

                # Push back updated count
                if count + 1 < 0:
                    heapq.heappush(heap, (count + 1, char))

        return ans
