# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self,root,subRoot):
        if not root and not subRoot:
            return True
        elif not root or not subRoot or root.val != subRoot.val:
            return False
        
        return self.helper(root.left,subRoot.left) and self.helper(root.right,subRoot.right)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root:
            return False
        
        if root.val == subRoot.val and self.helper(root,subRoot):
            return True
        
        return self.isSubtree(root.left,subRoot) or self.isSubtree(root.right,subRoot)
        
        
        
        
       