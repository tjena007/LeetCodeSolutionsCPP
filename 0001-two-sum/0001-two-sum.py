class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i in range(0,len(nums)):
            d[nums[i]] = d.get(nums[i],[])
            d[nums[i]].append(i)
        
        for i in range(0,len(nums)):
            to_find = target - nums[i]
            if to_find in d and d[to_find][0] != i:
                if to_find == nums[i] and len(d[to_find]) > 1:
                    return [d[to_find][0],d[to_find][1]]
                else:
                    return [i,d[to_find][0]]
