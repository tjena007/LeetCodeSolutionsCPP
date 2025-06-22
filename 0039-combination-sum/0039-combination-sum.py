class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        self.s = set()

        def dfs(arr,i,curSum):
            # if arr == [2, 2, 3] or arr==[7]:
            #     print(curSum,i)
            if curSum == target:
                self.s.add(tuple(arr))
                return
            if i == len(candidates) or curSum > target or candidates[i] > target or curSum + candidates[i] > target :
                return
            
            
            
            # same index again
            arr.append(candidates[i])
            dfs(arr,i,curSum + candidates[i])
            arr.pop() #needs some condition
            # next index
            dfs(arr,i+1,curSum)
        
        dfs([],0,0)

        return [list(i) for i in self.s]
        
