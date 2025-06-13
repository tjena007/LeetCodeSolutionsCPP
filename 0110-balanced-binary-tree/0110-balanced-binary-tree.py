# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:    
        def helper(root):
            if not root:
                return [0,True]
            
            left = helper(root.left)
            right = helper(root.right)

            h = 1 + max(left[0],right[0])

            if left[1] == False or right[1] == False or abs(left[0]-right[0]) > 1:
                return [h,False]
            
            return [h,True]
        
        ans = helper(root)
        return ans[1]
        