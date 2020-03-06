Description
--
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```
But the following [1,2,2,null,3,null,3] is not:
```
    1
   / \
  2   2
   \   \
   3    3
```

cpp solutions 
---
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return checkSym(root->left,root->right);
    }
    
    bool checkSym(TreeNode* p, TreeNode* q){
        if (!p && !q) return true;
        if (!p || !q) return false;
        return (p->val==q->val) && checkSym(p->left,q->right) && checkSym(p->right,q->left);
    }
};
```


Some Ideas
--
Similar to the one checking whether two trees are the same. I think the common mistake is to misunderstand the problem. The symmetric here means the tree is like a mirror, but not means the left and right node are the same.

Another way to use [BFS](https://leetcode.com/problems/symmetric-tree/discuss/33089/My-C%2B%2B-Accepted-code-in-16ms-with-iteration-solution) iterately to solve the problem
