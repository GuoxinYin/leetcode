Description
--
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

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
return its minimum depth = 2.

cpp solutions 
---
#### DFS
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return minDepth(root->right) + 1;
        if (root->left) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
```
#### BFS
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        deque<TreeNode *> d;
        d.push_back(root);
        int count = 0;
        while(!d.empty()) {
            int n = d.size();
            count++;
            bool flag = false;
            for (int i = 0; i<n; ++i) {
                TreeNode *temp = d.front();
                d.pop_front();
                if (!temp->left) {
                    if (!temp->right) {
                        flag = true;
                        break;
                    } 
                    d.push_back(temp->right);
                } else {
                    d.push_back(temp->left);
                    if (temp->right) d.push_back(temp->right);
                }
            }
            if (flag) break;
        }
        return count;
    }
    
};
```

Some Ideas
--
When constructing the DFS, one common mistake about the recursive relation is when a node has only one child. Note that the depth should be from root to leaf, where **leaf** has no child. Therefore, those with only one child cannot be applied with `min(depth(left),depth(right))+1` cuz the `min` here will return 0.

Another mistake is that when realizing the above error, one may think that those node has depth 2, which is also wrong, like the following example:
```
1
 \
  2
   \
    3
     \
      4
```
where the depth of `3` is 2, while the depth of `2` is `depth(3)+1=3`.
