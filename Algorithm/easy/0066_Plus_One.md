Description
--
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example
--
1. Input: [1,2,3] Output: [1,2,4] Explanation: The array represents the integer 123.
2. Input: [4,3,2,1] Output: [4,3,2,2] Explanation: The array represents the integer 4321.

cpp solutions 
---
```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        for (; i >=0; --i){
            if (digits[i]!=9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        vector<int> vec(digits.size()+1);
        vec[0] = 1;
        return vec;
    }
};
```

Some Ideas
--
1. In the beginning, I naively think that we just need to add one to the last digit in the array. However, when the input is 9, the output is [1,0] rather than [10]. Also pay attention to the numbers like 9, 99, 999 and so on, where we should finally add one addtional `'1'` in the beginning of the return value.
2. when checking whether we need to add `'1'`, since all other valid cases should be dealt within the `for` loop, and also notice that this case will give us a vector with one `'1'` in the beginning and a bunch of `'0'` following it, we just need to create a zero vector with size as `digits.size()+1` and make the first element as 1.
