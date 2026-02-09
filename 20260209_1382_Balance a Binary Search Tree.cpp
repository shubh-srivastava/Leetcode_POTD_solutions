// 9th feb 2026

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
    void inorder(TreeNode* node,vector<int>& vals){
        if(node == NULL){
            return;
        }

        inorder(node->left,vals);
        vals.push_back(node->val);
        inorder(node->right,vals);
    }

    TreeNode* makeTree(vector<int>&vals,int l,int r){
        if(l > r){
            return NULL;
        }
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(vals[mid]);
        
        node->left = makeTree(vals,l,mid-1);
        node->right = makeTree(vals,mid+1,r);

        return node;
    }
    TreeNode* balanceBST(TreeNode* root){
        vector<int>vals;
        inorder(root,vals);

        return makeTree(vals,0,vals.size()-1);                        
    }
};