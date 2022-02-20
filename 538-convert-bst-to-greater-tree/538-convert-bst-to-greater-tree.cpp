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
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        int sum = 0;
        root->val = helper(root,sum);
        
        return root;
    }
    
    int helper(TreeNode* root,int& sum){
        if(root == NULL){
            return 0;
        }
        int right = helper(root->right,sum);
        sum+=root->val;
        root->val = sum;
        
        //cout << sum  << " ";
        helper(root->left,sum);
        
        return root->val;
    }
};