Description
--
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

Example
--
Given binary tree [3,9,20,null,null,15,7],
```
    3
   / \
  9  20
    /  \
   15   7
```
return its bottom-up level order traversal as:
```
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        deque<TreeNode *> q;
        q.push_back(root);
        vector<vector<int>> vec;
        while (!q.empty()) {
            size_t count = q.size();
            vector<int> v;
            for (int i=0; i<count; ++i){
                TreeNode * temp = q.front();
                q.pop_front();
                if (!temp) continue;
                v.push_back(temp->val);
                q.push_back(temp->left);
                q.push_back(temp->right);
            }
            if (!v.empty()) vec.push_back(v);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
```


Some Ideas
--
1. It is possible that in the inner `for` loop, we don't push anything into `v`. Therefore, we need to check whether `v` is empty.
