class Solution:
    def rob(self, nums: List[int]) -> int:
        N = len(nums) + 1
        dp = [0] * N
        dp[1] = nums[0]

        for i in range(2,N):
            dp[i] = max(dp[i-2]+ nums[i-1], dp[i-1])
        
        return dp[N-1]
