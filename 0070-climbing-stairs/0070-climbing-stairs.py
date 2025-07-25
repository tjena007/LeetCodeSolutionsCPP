class Solution:
    def climbStairs(self, n: int) -> int:
        memo = [0] * (n + 1)

        def helper(k):
            if k <= 2:
                return k
            if memo[k] != 0:
                return memo[k]
            memo[k] = helper(k - 1) + helper(k - 2)
            return memo[k]

        return helper(n)
