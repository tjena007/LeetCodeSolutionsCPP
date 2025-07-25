class Solution:
    def climbStairs(self, n: int) -> int:
        if n <=2:
            return n
        res = [0] * (n+1)
        res[1],res[2] = 1,2

        def helper(k):
            if res[k] > 0:
                return res[k]
            
            n1,n2 = helper(k-1),helper(k-2)
            res[k-1],res[k-2] = n1,n2
            return n1+n2 
        
        return helper(n)