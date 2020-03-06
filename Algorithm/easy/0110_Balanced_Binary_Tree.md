Description
--
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example
--
1. Given the following tree [3,9,20,null,null,15,7]:

```
    3
   / \
  9  20
    /  \
   15   7
```
Return true.

2. Given the following tree [1,2,2,3,3,null,null,4,4]:
```
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
```
Return false.

cpp solutions 
---
#### First Attempt
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return helper(root) && isBalanced(root->left) && isBalanced(root->right);
    }

    bool helper(TreeNode *root) {
        if (!root) return true;
        return abs(height(root->left)-height(root->right))<=1;
    }

    int height(TreeNode* root) {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};
```
#### Second Attempt
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
    
    int height(TreeNode* root) {
        if (!root) return 0;
        int left = height(root->left);
        if (left == -1) return -1;
        int right = height(root->right);
        if (right == -1) return -1;
        if (abs(left-right)>1) return -1;
        return max(left,right) + 1;
    }
};
```

Some Ideas
--
It is important to know that to have a balanced tree, we cannot simply make sure the balance of the `root`, or only `root`, `root->left` and `root->right`, we need to make sure every node is balanced. The second method is learnt from [here](https://leetcode.com/problems/balanced-binary-tree/discuss/35691/The-bottom-up-O(N)-solution-would-be-better).
