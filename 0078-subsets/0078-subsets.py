class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.s = set()
        self.s.add(tuple([]))
        arr = []

        def dfs(arr,nums,i):
            if i == len(nums):
                self.s.add(tuple(arr))
                return
            
            # taken
            arr.append(nums[i])
            dfs(arr,nums,i+1)

            # not taken
            arr.pop()
            dfs(arr,nums,i+1)


        dfs(arr,nums,0)
        ans = [list(i) for i in self.s]

        return ans



        