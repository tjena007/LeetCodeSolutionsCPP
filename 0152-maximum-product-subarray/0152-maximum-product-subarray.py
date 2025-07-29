class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = max(nums)
        currMax,currMin = 1,1

        for num in nums:
            if num == 0:
                #reset
                currMax,currMin = 1,1
                continue
            
            tmp = num * currMax
            currMax = max(tmp,num * currMin,num)
            currMin = min(tmp,num * currMin,num)
            res = max(res,currMax)

        return res

