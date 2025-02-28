class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        def findSum(i,curr,total):
            if total == target:
                res.append(curr.copy())
                return
            if total > target or i >= len(candidates):
                return
            
            curr.append(candidates[i])
            findSum(i,curr,total+candidates[i])
            curr.pop()
            findSum(i+1,curr,total)
            return
        
        findSum(0,[],0)
        return res