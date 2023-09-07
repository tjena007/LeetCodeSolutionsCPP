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
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
    
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> ans;
        
        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }
        
        if(start == end){
            TreeNode* root = new TreeNode(start);
            ans.push_back(root);
            return ans;
        }
        
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftSubtrees = generate(start, i-1);
            vector<TreeNode*> rightSubtrees = generate(i+1, end);
        
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
};