class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = float('-inf')

        currSum = 0

        for num in nums:
            currSum += num
            ans = max(ans,currSum,num)

            currSum = max(currSum, num)
        
        return ans