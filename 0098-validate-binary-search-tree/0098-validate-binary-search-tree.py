# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def dfs(root,lb,ub):
            if not root:
                return True
            
            if not (lb < root.val < ub):
                return False
            
            return dfs(root.left,lb,root.val) and dfs(root.right,root.val,ub)
        
        return dfs(root,float('-inf'),float('inf'))
            