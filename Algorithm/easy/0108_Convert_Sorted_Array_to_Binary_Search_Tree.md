Description
--
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example
--
Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
```
      0
     / \
   -3   9
   /   /
 -10  5
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) return nullptr;
        int begin = 0;
        int end = nums.size();
        return helper(begin, end, nums);
    }

    TreeNode *helper(int begin, int end, vector<int> &nums) {
        if (begin >= end) return nullptr;
        int mid = (begin + end) / 2;
        TreeNode *q = new TreeNode(nums[mid]);
        q->left = helper(begin, mid, nums);
        q->right = helper(mid + 1, end, nums);
        return q;
    }
};
```


Some Ideas
--
Please remember to **new** when creating a node......(It takes me a hour to debug...I totally forget the dynamic memory...)
