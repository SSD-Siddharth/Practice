/*
Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


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

/*
Algo
Create a queue(Q)
enqueue(root)
while Queue is not empty
    enqueue() the child of first element 
    dequeue() and print
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        cout<<size;
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
    return res;
    }
};