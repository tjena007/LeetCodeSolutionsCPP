class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        # make copies
        def dfs(arr,nums):
            if len(nums) == 0:
                ans.append(arr.copy())
                return
            
            for i in range(len(nums)):
                dfs(arr + [nums[i]], nums[:i] + nums[i+1:])
        
        dfs([],nums)

        return ans