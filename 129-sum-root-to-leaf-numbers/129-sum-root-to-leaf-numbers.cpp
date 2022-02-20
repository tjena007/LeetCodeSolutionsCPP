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
    int sumNumbers(TreeNode* root) {
        //cout << stoi("2147483647");
        if(root == NULL)return NULL;
        vector<long> nums;
        helper(root,0,nums);
        int sum=0;
        for(auto i: nums){
            sum+=i;
        }
        
        return sum;
    }
    
    void helper(TreeNode* root,long prod,vector<long>&nums){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            nums.push_back(prod+root->val);
        }
        helper(root->left,(prod+root->val) * 10,nums);
        helper(root->right,(prod+root->val) * 10,nums);
        
        return;
    }
};