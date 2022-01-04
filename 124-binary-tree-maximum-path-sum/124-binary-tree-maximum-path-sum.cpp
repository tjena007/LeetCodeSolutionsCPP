/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
       findDistance(root); 
        
       return ans;
    }
    int findDistance(TreeNode* root){
        if(root == NULL) return 0;
        
        int ld = findDistance(root -> left);
        if(ld<0) ld=0;
        int rd = findDistance(root -> right);
        if(rd<0) rd=0;
        int rod = root->val;
        
        ans = max(ans,ld+rd+rod);
        
        // if(max(ld,rd)+rod < rod){
        //     return rod;
        // }
        return max(ld,rd)+rod;
    }
};