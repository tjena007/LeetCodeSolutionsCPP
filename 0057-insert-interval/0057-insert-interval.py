class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = []

        for start,end in intervals:
            if newInterval[1] < start:
                ans.append(newInterval)
                ans.extend(intervals[intervals.index([start,end]):])
                return ans

            elif newInterval[0] > end:
                ans.append([start,end])
            
            else:
                newInterval[0] = min(newInterval[0],start)
                newInterval[1] = max(newInterval[1],end)
        
        ans.append(newInterval)
        return ans
            

