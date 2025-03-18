class Solution:
    def isPalindrome(self, s: str) -> bool:
        l,r = 0,len(s) - 1
        def valid(ch):
            return ((ch >= "a" and ch <= "z") or (ch >= "A" and ch <= "Z") or (ch >= "0" and ch <= "9"))

        while l <= r:
            if valid(s[l]) == False:
                l+= 1
                continue
            elif valid(s[r]) == False:
                r -= 1
                continue
            elif s[l].lower() != s[r].lower():
                return False
            
            l+=1
            r-=1
        
        return True
