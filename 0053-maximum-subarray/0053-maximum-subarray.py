class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        currSum, ans = float('-inf'),float('-inf')

        for num in nums:
            currSum = max(num, currSum + num)

            ans = max(ans,currSum)
        
        return ans