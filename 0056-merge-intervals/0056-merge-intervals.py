class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        ans = []

        for s,e in intervals:
            if not ans or s > ans[-1][1]:
                # print('here', ans, s,e)
                ans.append([s,e])
            
            else:
                # print('here2', ans, s,e)
                ans[-1][0] = min(ans[-1][0],s)
                ans[-1][1] = max(ans[-1][1],e)
        
        return ans
