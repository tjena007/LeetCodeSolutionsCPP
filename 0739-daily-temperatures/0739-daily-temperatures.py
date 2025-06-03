class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [0] * len(temperatures)

        st = []

        for i,t in enumerate(temperatures):
            while st and t > st[-1][0]:
                tempSt,tempI = st.pop()
                ans[tempI]  = i - tempI
            
            st.append([t,i])
        
        return ans
            
