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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        map<int,int> nodes;
        queue<pair<TreeNode*,int>> todo;
        
        todo.push({root,0});
        
        while(!todo.empty()){
            int size = todo.size();
            for(int i=0;i<size;i++){
                auto p = todo.front();
                todo.pop();
                TreeNode* node = p.first;
                //cout << node->val << endl;
                int x=p.second;
                if(nodes.find(x) == nodes.end()){
                    nodes[x] = node->val;
                }
                
                if(node->right != NULL){
                    todo.push({node->right,x+1});
                }
                if(node->left != NULL){
                    todo.push({node->left,x+1});
                }
            }
        }
        
        for(auto i: nodes){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};