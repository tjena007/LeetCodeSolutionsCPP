class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        array_of_arrays = [[position[i],speed[i]] for i in range(0,len(speed))]
        array_of_arrays.sort(key=lambda x: x[0], reverse=True)

        time = []
        for i in array_of_arrays:
            t = (target - i[0]) / i[1]
            time.append(t)
        
        st = []

        for i in time:
            if not st:
                st.append(i)
            elif i > st[-1]:
                st.append(i)

        return len(st)