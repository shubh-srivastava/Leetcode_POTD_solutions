// 7TH JAN 2026
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
long long totSum = 0;
long long maxProd = 0;
int Mod = 1e9+7;
    long long getTotal(TreeNode* node){
        if(!node) return 0;
        return node->val + getTotal(node->left) + getTotal(node->right);
    }

    long long dfs(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        long long sum = 0;
        long long left = dfs(node->left);
        long long right = dfs(node->right);
        sum = left + right + node->val;
        maxProd = max(maxProd,(totSum-sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root){
        totSum = getTotal(root);
        dfs(root);
        return maxProd%Mod;
    }
};