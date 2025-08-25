class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m,n = len(matrix),len(matrix[0])
        l,r = 0, m-1

        row_to_find = -1
        
        while l<=r:
            mid = (l+r) // 2
            if target >= matrix[mid][0] and target <= matrix[mid][n-1]:
                row_to_find = mid
                break
            elif target < matrix[mid][0]:
                r = mid - 1
            else:
                l = mid + 1
        
        if row_to_find == -1:
            return False
        
        l,r = 0,n

        while l<=r:
            mid = (l+r) // 2
            if target == matrix[row_to_find][mid]:
                return True
            elif target > matrix[row_to_find][mid]:
                l = mid + 1
            else:
                r = mid - 1
        
        return False