class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        candidates.sort()

        def dfs(idx,curSum,arr):
            if curSum == target:
                ans.append(arr.copy())
                return
            
            if idx == len(candidates) or curSum > target:
                return

            arr.append(candidates[idx])
            dfs(idx+1,curSum + candidates[idx],arr)
            arr.pop()


            while idx+1 < len(candidates) and candidates[idx] == candidates[idx+1]:
                idx = idx + 1

            dfs(idx+1,curSum,arr)


        dfs(0,0,[])

        return ans