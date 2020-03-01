Description
--
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example
--
1. Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.

2. Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
It doesn't matter what values are set beyond the returned length.

cpp solutions
--
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int>::iterator itt = ++nums.begin();
        int len = 1;
        for (;itt!=nums.end();++itt){
            if (*itt != nums[len-1]){
                nums[len] = *itt;
                len++;
            }
        }
        return len;
    }
};
```

Some Ideas
--
Two pointer problem! Ooooh, it reminds me of the EECS281 course I took last semester in UMich and the IA mentions this algorithm in the lab...But it turns out even if I didn't understand it at that time, I can still use it to solve problem without realizing that I can master it! Woohoo!

