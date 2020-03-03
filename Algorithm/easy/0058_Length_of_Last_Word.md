Description
--
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example
--
Input: "Hello World" Output: 5

cpp solutions 
---
```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t find = s.find_last_of(" ");
        string sub = s.substr(find+1);
        while (sub.size() == 0 && s.substr(0,find) != ""){
            s= s.substr(0,find);
            find = s.find_last_of(" ");
            sub = s.substr(find+1);
        }
        return sub.size();
    }
};
```
Python3 solutions
---
```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        myList = s.split()
        if not myList:
            return 0
        return len(myList[-1])
```

Some Ideas
--
#### For cpp: 
need to take care of the case when input is "Hello World ". Note that there is no word after the last empty space. However, in this case we need to find the word before the last empty space.
#### For python:
need to take care of the case when input is "" or " ". In these cases, `myList=[]`, thus it is invalid to access `myList[-1]`. Also need to pay attention to the syntax of checking whether the list is empty: `if not myList:`.
