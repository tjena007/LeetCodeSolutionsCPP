class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        memo = {}

        def dfs(i):
            if i in memo:
                return memo[i]
            
            longest = 1
            for j in range(i+1,n):
                if nums[j] > nums[i]:
                    longest = max(longest,1 + dfs(j))
                
            memo[i] = longest
            return longest
        
        return max(dfs(i) for i in range(n))