class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        A,B = nums1, nums2
        
        total = len(A)  + len(B)
        half = total // 2

        if len(A) > len(B):
            A,B = B,A
        
        l,r = 0, len(A) - 1 #index

        while True:
            i = (l+r) // 2 #elements to take from A
            j = half - i - 2

            leftA = A[i] if i>=0 else float('-inf')
            rightA = A[i+1] if i+1 < len(A) else float('inf')
            
            leftB = B[j] if j>=0 else float('-inf')
            rightB = B[j+1] if j+1 < len(B) else float('inf')

            if leftA <= rightB and leftB <= rightA:
                if total % 2:
                    return min(rightA,rightB)
                else:
                    return (max(leftA,leftB) + min(rightA,rightB)) / 2
            elif leftA > rightB:
                r = i - 1
            else:
                l = i + 1
        
        return 0 #dummy

