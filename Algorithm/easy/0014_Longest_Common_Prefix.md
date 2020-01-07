Description
--
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example
--
1. Input: ["flower","flow","flight"] Output: "fl"
2. Input: ["dog","racecar","car"] Output: "" Explanation: There is no common prefix among the input strings.

Note
--
All given inputs are in lowercase letters `a-z`.

cpp solutions
--
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0){ //This is necessary. Otherwise, it is possible that strs[0] doesn't exist.
            return "";
        }
        string result = "";
        for (size_t i=0; i<strs[0].size(); ++i){
            for (size_t j=1; j<strs.size(); ++j){
                if (strs[j][i]!=strs[0][i]){
                    return result;
                }
            }
            result += strs[0][i];
        }
        return result;
    }
};
```

Some Ideas
--
Brute Force. Compare each character in each string.

