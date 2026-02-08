//8th feb 2026

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

    int check(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int lh = check(node->left);
        int rh = check(node->right);
        if(lh == -1 || rh == -1){
            return -1;
        }
        if(abs(lh-rh)>1){
            return -1;
        }
        return max(lh,rh)+1;
    }

    bool isBalanced(TreeNode* root){
        if(root == NULL){
            return true;
        }    

        return (check(root) != -1);          

    }
};