class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []

        nums.sort()
        s = set()
        
        for i in range(0,len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            target = 0 - nums[i]
            left,right = i+1,len(nums)- 1

            while left<right:
                if nums[left] + nums[right] == target:
                    s.add((nums[i],nums[left],nums[right]))
                    # add check to increment the left and right pointers
                    

                    left+=1
                    while left < right and left < len(nums) and nums[left] == nums[left - 1]:
                        left +=1
                    
                    
                    while left < right and right > 0 and nums[right] == nums[right - 1]:
                        right -=1
                
                elif nums[left] + nums[right] > target:
                    right -= 1
                else:
                    left += 1
        
        ans = []
        for item in s:
            ans.append(list(item))
        
        return ans

