class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        idx_to_compare = 0
        ans = 0

        for i in range(1,len(intervals)):
            start,end = intervals[i]

            if start < intervals[idx_to_compare][1]:
                ans += 1
                # keep the interval with smaller end
                if end < intervals[idx_to_compare][1]:
                    idx_to_compare = i
            else:
                idx_to_compare = i
        

        return ans

