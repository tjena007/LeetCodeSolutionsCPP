class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        count = {}
        for num in nums:
            count[num] = count.get(num,False)
        
        ans = 0
        for num in nums:
            if num - 1 in count or count[num] == True:
                continue
            
            c = 0
            while num in count:
                count[num] = True
                c += 1
                num += 1
            ans = max(ans,c)
        

        return ans