# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self,root) -> int:
        if not root:
            return 0

        left = 1 + self.helper(root.left) if root.left else 0
        right = 1 + self.helper(root.right) if root.right else 0

        self.ans = max(self.ans,left + right)

        return max(left,right)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        self.helper(root)
        return self.ans
