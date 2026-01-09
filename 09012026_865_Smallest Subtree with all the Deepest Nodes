// 9TH JAN 2026
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
unordered_map<int,int>mp;
int maxD = 0;

    TreeNode* LCA(TreeNode* node){
        if(node == NULL || mp[node->val] == maxD){
            return node;
        }

        TreeNode* l = LCA(node->left);
        TreeNode*r = LCA(node->right);

        if(l && r){
            return node;
        }
        if(l){
            return l;
        }
        return r;
    }
    void height(TreeNode* node,int d){
        if(!node){
            return;
        }
        maxD = max(d,maxD);
        mp[node->val] = d;
        height(node->left,d+1);
        height(node->right,d+1); 
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root){
        height(root,0);

        return LCA(root);
        
    }
};