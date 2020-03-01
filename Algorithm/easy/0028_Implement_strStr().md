Description
--
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example
--
1. Input: haystack = "hello", needle = "ll" Output: 2
2. Input: haystack = "aaaaa", needle = "bba" Output: -1

cpp solutions 
---
```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (needle.length()>haystack.length()) return -1;
        int len = needle.length();
        for (int i=0; i<=haystack.size()-len;++i){
            if (haystack.substr(i,len) == needle) return i;
        }
        return -1;
    }
};
```

Some Ideas
--
Need to consider the validation of `substr()` function, i.e. what if the `len` is larger than the whole size of the `haystack` string.

#### Mistake:
1. Neglect whether `substr()` is valid or not
2. Only consider the case when `haystack` is `""` but neglect the case when `haystack="aa"` while `needle="aaa"`
