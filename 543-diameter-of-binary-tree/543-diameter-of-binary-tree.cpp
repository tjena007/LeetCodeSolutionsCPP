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
    int ans = -1;
    int diameterOfBinaryTree(TreeNode* root) {
        
        height(root);
        return ans;
    }
    
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int lh = height(root->left);
        //cout << lh << endl;
        int rh = height(root->right);
        //cout << rh << endl;
        ans = max(ans,lh+rh);
        
        return 1+ max(lh,rh);
    }
};