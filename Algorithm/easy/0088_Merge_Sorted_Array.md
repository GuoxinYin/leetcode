Description
--
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example
--
Input:

nums1 = [1,2,3,0,0,0], m = 3

nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

cpp solutions 
---
```cpp
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0) {
            return;
        }
        int i = 0;
        int j = m;
        for (int k = m; k < m + n; k++) {
            nums1[k] = nums2[k - m];
        }
        while (i<j) {
            if (nums1[i] <= nums1[j]) i++;
            else {
                swap(nums1[i], nums1[j]);
                i++;
                int k = j;
                while (k<m+n-1){
                    if (nums1[k+1]<nums1[k]) {
                        swap(nums1[k+1],nums1[k]);
                        k++;
                    } else break;
                }
            }
        }
    }
};
```


Some Ideas
--
My way is to append the value of `num2` to `num1` and then once we swap two values, we keep the new `num2` part sorted.

[Another way](https://leetcode.com/problems/merge-sorted-array/discuss/29522/This-is-my-AC-code-may-help-you):
```cpp
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i=m-1;
		    int j=n-1;
		    int k = m+n-1;
		    while(i >=0 && j>=0){
			      if(A[i] > B[j]) A[k--] = A[i--];
			      else A[k--] = B[j--];
		    }
		    while(j>=0)
			    A[k--] = B[j--];
    }
};
```
