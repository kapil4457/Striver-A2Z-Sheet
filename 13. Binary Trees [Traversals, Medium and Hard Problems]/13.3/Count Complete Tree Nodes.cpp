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
    int countNodes(TreeNode* root) {
                vector<int>ans;

if(root==NULL){
    return ans.size();
}
        
        queue<TreeNode * >q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            
            TreeNode * node = q.front();
            q.pop();
            if(node!=NULL){
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                ans.push_back(node->val);

            }
            
           else if(!q.empty()){
                q.push(NULL);
            }
        }
        
        
        return ans.size();
    }
};