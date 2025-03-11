class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count  = {}
        for num in nums:
            count[num] = 1 + count.get(num,0)
        
        c = [[] for i in range(0,len(nums) + 1)]

        for key,value in count.items():
            c[value].append(key)
        
        # print(c)

        ans = []
        for i in range(len(c) - 1,0,-1):
            for j in range(0,len(c[i])):
                ans.append(c[i][j])
                if len(ans) == k:
                    return ans
