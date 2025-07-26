class Solution:
    def rob(self, nums: List[int]) -> int:
        N = len(nums) + 1
        dp = [-1] * N

        def dfs(idx):
            if idx <= 0:
                return 0

            if dp[idx] != -1:
                return dp[idx]
            
            dp[idx] = max(dfs(idx- 1),dfs(idx- 2) + nums[idx-1])

            return dp[idx]
        
        return dfs(N-1)