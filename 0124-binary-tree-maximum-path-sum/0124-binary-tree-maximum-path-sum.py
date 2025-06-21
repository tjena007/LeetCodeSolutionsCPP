# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.ans = float('-inf')

        def dfs(root, curSum):
            if not root:
                return 0
            
            # check with just root
            self.ans = max(self.ans,root.val)

            leftSum = dfs(root.left, curSum)
            rightSum = dfs(root.right, curSum)

            # check with root + left
            self.ans = max(self.ans, root.val + leftSum)
            
            # check with root + right
            self.ans = max(self.ans, root.val + rightSum)
            
            # check with root + left + right
            self.ans = max(self.ans, root.val + rightSum + leftSum)
            
            #return max(root,root + left,root + right)
            return max(root.val,root.val + leftSum, root.val + rightSum)
        

        dfs(root,0)

        return self.ans