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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>levelSums;

        while(!q.empty()){
            int levelSize=q.size();
            int levelSum=0;
            for(int i=0;i<levelSize;i++){
                TreeNode* node=q.front();
                q.pop();
                levelSum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            levelSums.push_back(levelSum);

        }
        q.push(root);
        root->val=0;
        int level=0;
        while(!q.empty()){
            int levelSize=q.size();
            for(int i=0;i<levelSize;i++){
                TreeNode* node=q.front();
                q.pop();


                int siblingsSum=0;
                if(node->left)siblingsSum+=node->left->val;
                if(node->right) siblingsSum+=node->right->val;

                if(node->left){
                    node->left->val=levelSums[level+1]-siblingsSum;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val=levelSums[level+1]-siblingsSum;
                    q.push(node->right);
                }

            }
            level++;
        }
        return root;
    }
};