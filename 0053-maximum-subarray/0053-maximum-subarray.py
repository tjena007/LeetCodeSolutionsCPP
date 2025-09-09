class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        currSum, ans = float('-inf'),float('-inf')

        for num in nums:
            # print(num,':',currSum,ans)
            if num > currSum:
                currSum = max(num, currSum + num)
            else:
                currSum = currSum + num

            ans = max(ans,currSum)
        
        return ans