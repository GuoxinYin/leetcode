Description
--
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example
--
1. Input: [1,3,5,6], 5 Output: 2
2. Input: [1,3,5,6], 2 Output: 1
3. Input: [1,3,5,6], 7 Output: 4
4. Input: [1,3,5,6], 0 Output: 0

cpp solutions 
---
#### First Attempt O(n)
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i=0;i<nums.size();++i){
            if (nums[i]>=target) return i;
        }
        return nums.size();
    }
};
```
#### Second Attempt O(log(n))
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size();
        while (begin<end){
            int mid = (begin+end)/2;
            if (nums[mid]<target){
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        return begin;
    }
};
```

Some Ideas
--
Typical binary search problem...Pay attention to the implementation of the binary search algorithm.
