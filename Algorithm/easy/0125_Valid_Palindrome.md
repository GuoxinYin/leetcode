Description
--

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example
--

```
Input: "A man, a plan, a canal: Panama"
Output: true
```

```
Input: "race a car"
Output: false
```

cpp solutions
---

#### My attempt

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if (s=="") return true;
        string str;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]>='A' && s[i]<='Z') str.push_back(s[i]+'a'-'A');
            else if ((s[i]>='a'&& s[i]<='z')||(s[i]>='0'&&s[i]<='9')) str.push_back(s[i]);
        }
        for (int i = 0; i <str.size()/2; ++i) {
            if (str[i]!=str[str.size()-i-1]) return false;
        }
        return true;
    }
};
```

#### Elegant [Method](https://leetcode.com/problems/valid-palindrome/discuss/40048/Here's-a-clean-C%2B%2B-solution) from Discussion

```cpp
bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }
    return true;
}
```



Some Ideas
--

Pay attention to the meaning of **alphanumeric**, it includes 0-9, a-z, A-Z. 
