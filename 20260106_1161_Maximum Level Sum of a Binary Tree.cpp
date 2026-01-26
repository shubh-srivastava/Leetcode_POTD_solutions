// 6th JAN 2026
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
    int maxLevelSum(TreeNode* root){
        int maxS = INT_MIN;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,int>mp;
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int h = q.front().second;
            q.pop();

            mp[h] += temp->val;

            if(temp->left){
                q.push({temp->left,h+1});
            }

            if(temp->right){
                q.push({temp->right,h+1});
            }
        }        
        int lev = -1;
        for(auto it : mp){
            if(maxS < it.second){
                maxS = it.second;
                lev = it.first;
            }
        }
        return lev+1;
    }
};