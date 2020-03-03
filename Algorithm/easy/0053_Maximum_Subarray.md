Description
--
Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example
--
Input: [-2,1,-3,4,-1,2,1,-5,4], Output: 6, Explanation: [4,-1,2,1] has the largest sum = 6.

cpp solutions 
---
#### Dynamic Programming
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> vec(nums.size());
        vec[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            vec[i] = max(vec[i-1]+nums[i],nums[i]);
        }
        int maxv = vec[0];
        for (int i = 1; i<vec.size(); ++i){
            if (vec[i]>maxv) maxv = vec[i];
        }
        return maxv;
    }
};
```
#### Divide and Conquer
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return INT_MIN; // Pay attention to the INT_MIN here, note that simply set it to zero will cause [-2,-1] return 0 rather than -1
        if (nums.size() == 1) return nums[0]; 
        int begin = 0;
        int end = nums.size();
        int mid = (begin+end)/2;
        vector<int> vec (nums.begin(),nums.begin()+mid);
        vector<int> vec2 (nums.begin()+mid+1, nums.end());
        int left = maxSubArray(vec);
        int right = maxSubArray(vec2);
        
        int l_max = 0;
        int l = 0;
        for (int i = mid-1; i>=0; --i){
            l += nums[i];
            l_max = max(l,l_max);
        }
        int r_max = 0;
        int r = 0;
        for (int i = mid+1; i< end; ++i){
            r += nums[i];
            r_max = max(r, r_max);
        }
        return max(l_max+nums[mid]+r_max,max(left,right));
    }
};
```


Some Ideas
--
Easier to solve it using dynamic programming.

Note that when using divide and conquer, need to take care of the case when the maximum subarray contains the mid value in the vector.
