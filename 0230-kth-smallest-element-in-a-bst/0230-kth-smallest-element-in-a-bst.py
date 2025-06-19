# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.count = k
        self.ans = None

        def dfs(root):
            if not root or self.ans is not None:
                return
            
            dfs(root.left)
            self.count -= 1
            if self.count == 0:
                self.ans = root.val
                return
            dfs(root.right)
        
        dfs(root)
        return self.ans