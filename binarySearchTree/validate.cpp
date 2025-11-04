class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
        if(root == NULL) return true;
        if(root->val >= maxVal || root->val <= minVal) return false;
        return isValidBST(root->left, minVal, root->val) && 
               isValidBST(root->right, root->val, maxVal);
    }
};