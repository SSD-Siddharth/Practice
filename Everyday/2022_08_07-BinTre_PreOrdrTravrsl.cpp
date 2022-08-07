/*
Binary Tree Preorder Traversalv

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 
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
    vector<int> preorderTraversal(TreeNode* root) {
        /*
        Algo
        if(root==NULL) 
            //return error msg
        else 
            //print root
            preorderTraversal(root.left)
            preorderTraversal(root.right)      
   
   Root
   Left Subtree
   Right Subtree
   
        */
        
        
        //Using stack , this below code, is 100% faster
        vector<int> result;
        if(root==nullptr) 
            return result;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *temp = st.top();
            
            //result.push_back(st.top()->val);
            result.push_back(temp->val);
            st.pop();
            // right child in the bottom (stack FIFO)
            if(temp->right)
                st.push(temp->right);
            // left child in the top for Preorder
            if(temp->left)
                st.push(temp->left);
        }
        return result;
        /*
        //this is 70% faster, but I'm able to understand this one better
        
        vector<int> result;
        Pre_tree(root, result);
    return result;
    }
    void Pre_tree(TreeNode *root, vector<int> &v){
            // 1) if node is null, return;
            if(root == nullptr) return;

            // 2) visit left , output the val, then visit right; 
            v.push_back(root->val);
            Pre_tree(root->left, v);
            Pre_tree(root->right, v);
            /*
               Root
               Left Subtree
               Right Subtree
            */
    }
};