Description
--
Given two binary strings, return their sum (also a binary string).

The input strings are both **non-empty** and contains only characters `1` or `0`.

Example
--
1. Input: a = "11", b = "1" Output: "100"
2. Input: a = "1010", b = "1011" Output: "10101"

cpp solutions 
---
```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string str = "";
        int carry = 0;
        if (a.size()<b.size()){
            a = string(b.size()-a.size(),'0') + a;
        } else if (b.size()<a.size()){
            b = string (a.size()-b.size(),'0') + b;
        }
        for (int i = a.size()-1; i>=0; --i){
            int sum = a[i]-'0'+b[i]-'0'+carry;
            if (sum == 3) {
                str = "1" + str;
            } else if (sum == 2){
                str = "0" + str;
                carry = 1;
            } else {
                str = to_string(sum) + str;
                carry = 0;
            }
        }
        if (carry == 1){
            str = "1" + str;
        }
        return str;
    }
};
```


Some Ideas
--
Originally, I thought this is so easy, we just need to use `stoi` to turn the string into integer and then sum them up. But this has two shortcomings:
1. After we sum them up and use `to_string` to give the string form of it, it returns the decimal value, oh no...You still need to translate it into binary.
2. The above actually is not a problem. The biggest problem is that add two integer together may cause **overflow**!!! Oh, I really hate it.

I think to make two string the same size is helpful for solving this problem.

Finally, don't forget to add one extra `'1'` if the carry is still 1 in the end.

And I like the answer [here](https://leetcode.com/problems/add-binary/discuss/24475/Short-code-by-c%2B%2B)
