class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans = []

        def dfs(arr,i,curSum):
            if curSum == target:
                ans.append(arr.copy())
                return
            if i == len(candidates) or curSum > target:
                return
            
            # same index again
            arr.append(candidates[i])
            dfs(arr,i,curSum + candidates[i])
            arr.pop()
            # next index
            dfs(arr,i+1,curSum)
        
        dfs([],0,0)

        return ans
        
