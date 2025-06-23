class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []

        def dfs(i,arr):
            if i == len(nums):
                ans.append(arr.copy())
                return
            
            arr.append(nums[i])
            dfs(i+1,arr)
            arr.pop()

            while i+1 < len(nums) and nums[i+1] == nums[i]:
                i += 1
            
            dfs(i+1,arr)
        
        dfs(0,[])

        return ans