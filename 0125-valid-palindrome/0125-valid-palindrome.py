class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleanString = ''
        for c in s:
            if (c>= 'a' and c<= 'z') or (c>= 'A' and c<= 'Z') or (c>= '0' and c<= '9'):
                cleanString += c
        
        left,right = 0, len(cleanString)-1
        cleanString = cleanString.lower()
        
        while left <= right:
            if cleanString[left] != cleanString[right]:
                return False
            left += 1
            right -= 1
        
        return True