class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleanString = "".join(ch for ch in s if ((ch >= "a" and ch <= "z")
        or (ch >= "A" and ch <= "Z") or (ch >= "0" and ch <= "9"))).lower() 
        print(cleanString)

        return cleanString[::-1] == cleanString
