
class Solution {
public:
    /*
     * @param root: the root of tree
     * @return: the max node
     */
   TreeNode * helper(TreeNode * first,TreeNode * second){
        if(first==NULL){
            return second;
        }
        if(second==NULL){
            return first;
        }
        if(first->val<second->val){
            return second;
        }
        return first;
        
    }
    TreeNode * maxNode(TreeNode * root) {
        // write your code here
        if(root==NULL){
            return root;
        }
        // find the left most node
        TreeNode *left=maxNode(root->left);
        // find the right most node
        TreeNode *right=maxNode(root->right);
        // find the 
        return helper(root,helper(left,right));
    }
};