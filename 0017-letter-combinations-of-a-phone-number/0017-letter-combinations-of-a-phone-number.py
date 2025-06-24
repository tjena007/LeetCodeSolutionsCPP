class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        ans = []
        d= {
            "2" : "abc",
            "3" :  "def",
            "4" : "ghi",
            "5" :  "jkl",
            "6" : "mno",
            "7" :  "pqrs",
            "8" : "tuv",
            "9" :  "wxyz"
        }

        arr =[d[num] for num in list(digits)]
        maxL = max(arr)
        
        def dfs(s,idx):
            if len(s) == len(digits):
                ans.append(str(s)) 
                return
            
            for i in range(0,len(arr[idx])):
                s += arr[idx][i]
                dfs(s,idx + 1)
                s = s[:-1]
        

        dfs("",0)
        return ans
