/*
Two Sum IV - Input is a BST
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

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
    //We'll use InOrder to find two comb. that equals to target, as it'll be in Ascending order
    void inOrdr(TreeNode* root, vector<int> &ino){
        if(root==NULL) 
            return;
        inOrdr(root->left, ino);
        ino.push_back(root->val);
        inOrdr(root->right, ino);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> SavInordr;
        inOrdr(root, SavInordr); //Adding each elemnt of the tree into a vector in Ascending order
        int i = 0;   //first element, comparting each to get the target
        int j = SavInordr.size()-1;  //the last element
        
        while(i < j){
            int Sum = SavInordr[i] + SavInordr[j];
            if(Sum == k) 
                return true;
            else if(Sum > k)   //to decrease the sum value
                j--;
            else 
                i++;
        }
        return false;
    }
};