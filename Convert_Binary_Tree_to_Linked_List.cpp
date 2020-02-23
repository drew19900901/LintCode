class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    void helper(vector<ListNode *> & result,int height,TreeNode *root){
        if(root==NULL){
            return;
        }
        ListNode* currentNode= new ListNode(root->val);
        
        if(height>result.size()){
           result.push_back(currentNode);
        }
        else{
            currentNode->next=result[height-1];
            result[height-1]=currentNode;
        }
        helper(result,height+1,root->right);
        helper(result,height+1,root->left);
        
        
    }
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        // Write your code here
        vector<ListNode*> result;
        helper(result,1,root);
        return result;
    }
};