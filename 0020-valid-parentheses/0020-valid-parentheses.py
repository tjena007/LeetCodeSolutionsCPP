class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for c in s:
            if c == ')' or c == ']' or c == '}':
                if st and c == ')' and st[-1] == '(':
                    st.pop()
                elif st and c == ']' and st[-1] == '[':
                    st.pop()
                elif st and c == '}' and st[-1] == '{':
                    st.pop()
                else:
                    return False
            else:
                st.append(c)
        
        return  False if len(st) > 0 else True