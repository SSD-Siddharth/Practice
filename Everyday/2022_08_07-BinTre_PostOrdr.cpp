/*
Binary Tree Postorder Traversal
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        /*
        Algo
        Left Subtree
        Right Subtree
        Root
        */
        vector<int> result;
        Post_tree(root, result);
        return result;
    }
    void Post_tree(TreeNode *root, vector<int> &v){
            // 1) if node is null, return;
            if(root == nullptr) 
                return;

            // 2) visit left, then visit right, output the val,; 
            Post_tree(root->left, v);
            Post_tree(root->right, v);
            v.push_back(root->val);
            /*
              
               Left Subtree
               Right Subtree
                Root
            */
        
    }
};