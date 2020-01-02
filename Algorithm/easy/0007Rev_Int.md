Description
--
Given a 32-bit signed integer, reverse digits of an integer.

Example
--
1. Input: 123 Output: 321
2. Input: -123 Output: -321
3. Input: 120 Output: 21

Note
--
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [− $ 2^{31} $,  $ 2^{31} $ − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

cpp solutions
---
```cpp
class Solution {
public:
    int reverse(int x) {
        int count = 0;
        vector<char> vec;
        while (x!=0){
            int temp = x % 10;
            vec.push_back(temp);
            x = x/10;
            count ++;
        }
        int result = 0;
        for (int i=0; i<count; ++i){
            if ((result + vec[i]*pow(10, count-i-1))>INT_MAX || (result + vec[i]*pow(10, count-i-1))<INT_MIN){
                return 0;
            }
            result += vec[i]*pow(10, count-i-1);
        }
        return result;
    }
};
```
