class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = {}
        
        def dfs(amount,idx):
            if (amount,idx) in dp:
                return dp[(amount,idx)]
                
            if amount == 0:
                return 0
            if idx == len(coins):
                return float('inf')
            
            take = float('inf')
            if coins[idx] <= amount:
                take = 1 + dfs(amount - coins[idx],idx)

            notTake = dfs(amount,idx + 1)

            dp[(amount,idx)] = min(take,notTake)

            return dp[(amount,idx)]

        ans = dfs(amount,0)
        return -1 if ans == float('inf') else ans
