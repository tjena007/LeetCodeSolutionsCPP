class Solution:
    def isPalindrome(self, s: str) -> bool:
        l,r = 0,len(s) - 1
        def valid(ch):
            return ch.isalnum()

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
