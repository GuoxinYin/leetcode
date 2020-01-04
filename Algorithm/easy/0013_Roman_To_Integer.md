Description
--
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

|Symbol       |Value|
|---|---|
|I             |1|
|V             |5|
|X             |10|
|L            | 50|
|C           |  100|
|D           |  500|
|M           |  1000|

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example
--
1. Input: "III" Output: 3
2. Input: "IV" Output: 4
3. Input: "IX" Output: 9
4. Input: "LVIII" Output: 58 Explanation: L = 50, V= 5, III = 3.
5. Input: "MCMXCIV" Output: 1994 Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

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

