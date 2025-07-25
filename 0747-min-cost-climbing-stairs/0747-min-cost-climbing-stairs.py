class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        N = len(cost) + 1
        dp= [float('inf')] * N
        top = N - 1

        def dfs(n):
            if n < 0:
                return 0
            if dp[n] != float('inf'):
                return dp[n]
            
            price = min(dfs(n-1),dfs(n-2))
            
            if(n == top):
                return price
            
            dp[n] = price + cost[n]

            return dp[n]
            

        return dfs(top)