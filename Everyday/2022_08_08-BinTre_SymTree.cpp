/*
Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

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
    bool isMirror(TreeNode *t1, TreeNode *t2) {
        //Checking each of the sides
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL || t2 == NULL) return false;
        if(t1->val != t2->val) return false;
        
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root->left, root->right);
    }
};