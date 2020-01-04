Description
--
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example
--
1. Input: 121 Output: true
2. Input: -121 Output: false Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
3. Input: 10 Output: false Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

cpp solutions
--
```cpp
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (size_t i=0; i<s.size(); ++i){
            if (s[i]=='M'){
                result+=1000;
            } else if (s[i]=='D'){
                result +=500;
            } else if (s[i]=='C'){
                if (i+1<s.size()&&(s[i+1]=='D'||s[i+1]=='M')){
                    result -= 100;
                } else {
                    result += 100;
                }
            } else if (s[i]=='L'){
                result += 50;
            } else if (s[i]=='X'){
                if (i+1<s.size()&&(s[i+1]=='L'||s[i+1]=='C')){
                    result -= 10;
                } else {
                    result += 10;
                }
            } else if (s[i] == 'V') {
                result += 5;
            } else if (s[i] == 'I') {
                if (i+1<s.size()&&(s[i+1]=='X'||s[i+1]=='V')){
                    result -= 1;
                } else {
                    result += 1;
                }
            }
        }
        return result;
    }
};
```

Some Ideas
--
Kind of brute force solution, just analyse each character in the string.

