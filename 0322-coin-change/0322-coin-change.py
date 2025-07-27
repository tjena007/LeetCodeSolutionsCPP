class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = {}  # cache results for (amount, idx)
        
        def helper(amount, idx):
            # Check cache
            if (amount, idx) in memo:
                return memo[(amount, idx)]

            # Base cases
            if amount == 0:
                return 0
            if idx == len(coins):
                return float('inf')
            
            # Option 1: Take coin (if possible)
            take = float('inf')
            if coins[idx] <= amount:
                take = 1 + helper(amount - coins[idx], idx)  # stay at idx since unlimited
            
            # Option 2: Skip coin
            skip = helper(amount, idx + 1)
            
            # Cache and return
            memo[(amount, idx)] = min(take, skip)
            return memo[(amount, idx)]
        
        ans = helper(amount, 0)
        return -1 if ans == float('inf') else ans
