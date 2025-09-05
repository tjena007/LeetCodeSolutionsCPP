class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        result = []
        
        for s, e in intervals:
            # Case 1: new interval is completely before current interval
            if newInterval[1] < s:
                result.append(newInterval)
                result.extend(intervals[intervals.index([s, e]):])  # append the rest
                return result
            
            # Case 2: new interval is completely after current interval
            elif newInterval[0] > e:
                result.append([s, e])
            
            # Case 3: overlap — merge with newInterval
            else:
                newInterval[0] = min(newInterval[0], s)
                newInterval[1] = max(newInterval[1], e)
        
        # If we never returned inside loop, push the merged/new interval at the end
        result.append(newInterval)
        return result
