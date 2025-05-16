class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        d = set(nums)
        ans = 0
        
        for num in d:
            if num - 1 in d:
                continue
            curr = 0
            while num + curr in d:
                curr += 1
            
            ans = max(ans,curr)
        
        return ans