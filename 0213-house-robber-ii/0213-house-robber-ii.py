class Solution:
    def rob(self, nums: List[int]) -> int:
        def helper(arr):
            cost1,cost2 = 0,0 

            for num in arr:
                val = max(cost1 + num,cost2)
                cost1 = cost2
                cost2 = val
            
            return cost2
        

        return max(nums[0],helper(nums[1:]),helper(nums[:-1]))

