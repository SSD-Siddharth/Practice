/*
104. Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


Ex
Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2

*/


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
    int maxDepth(TreeNode* root) {
    /*
    //This below method, directly uses Binary Tree Level Order Traversal, and then finds the size of the list
    vector<vector<int>> res;
    int sz;
    if(!root) {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left !=NULL) 
                    q.push(node->left);
                if(node->right !=NULL) 
                    q.push(node->right);
                level.push_back(node->val);
            }
            res.push_back(level);
        }
    return res.size();
    */
        
        
    //Using recursion
    if(root == NULL) 
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
    }
};