# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.ans = 0 


        def dfs(root,currMax):
            if not root:
                return
            
            if root.val >= currMax:
                self.ans += 1
                currMax = root.val
            
            dfs(root.left,currMax)
            dfs(root.right,currMax)
            
        dfs(root,float('-inf'))
        return self.ans