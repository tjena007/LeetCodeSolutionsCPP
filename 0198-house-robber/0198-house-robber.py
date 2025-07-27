class Solution:
    def rob(self, nums: List[int]) -> int:
        cost1,cost2 = 0,0

        for num in nums:
            val = max(cost1 + num,cost2)
            cost1 = cost2
            cost2 = val
        
        return cost2

        