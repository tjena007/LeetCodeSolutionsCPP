# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.ans = float('-inf')

        def dfs(root):
            if not root:
                return 0
            
            leftSum = max(dfs(root.left), 0)
            rightSum = max(dfs(root.right), 0)

            # path passing through root
            self.ans = max(self.ans, root.val + leftSum + rightSum)

            # return the max one-side path for parent usage
            return root.val + max(leftSum, rightSum)
        
        dfs(root)
        return self.ans