class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []

        def palindrome(s):
            return s == s[::-1] #reverse
        

        def dfs(start,arr):
            if start == len(s):
                res.append(arr.copy())
                return
            

            for end in range(start,len(s)):
                #slicing
                if palindrome(s[start:end+1]):
                    arr.append(s[start:end+1])
                    dfs(end+1,arr)
                    arr.pop() #backtrack and explore other options
                
            
        dfs(0,[])

        return res

        
