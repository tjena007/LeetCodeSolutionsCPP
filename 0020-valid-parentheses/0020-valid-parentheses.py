class Solution:
    def isValid(self, s: str) -> bool:
        st = []

        for c in s:
            if st and c == '}' and st[-1] == '{':
                st.pop()
            elif st and c == ')' and st[-1] == '(':
                st.pop()
            elif st and c == ']' and st[-1] == '[':
                st.pop()
            else:
                st.append(c)
        
        return len(st) == 0

