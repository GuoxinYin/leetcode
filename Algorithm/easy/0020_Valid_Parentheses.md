Description
--
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.

Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example
--
1. Input: "()" Output: true
2. Input: "()[]{}" Output: true
3. Input: "(]" Output: false
4. Input: "([)]" Output: false
5. Input: "{[]}" Output: true

cpp solutions
--
```cpp
class Solution {
public:
    bool isValid(string s) {
        if (s.length()==0) return true;
        if (s.length()%2==1) return false;
        deque<char> str;
        for (int i=0; i<s.length();++i){
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
                str.push_back(s[i]);
            } else if (s[i]==']'){
                if (str.empty() || str.back() !='[') return false;
                str.pop_back();
            } else if (s[i]=='}'){
                if (str.empty() ||str.back() !='{') return false;
                str.pop_back();
            } else{
                if (str.empty() ||str.back() !='(') return false;
                str.pop_back();
            }
        }
        if (!str.empty()) return false;
        return true;
   }
};
```

Some Ideas
--
1. The first time I implement it, I made a mistake that I think all the valid parentheses should be in the form of Example 2, where we should compare the adjacent character to do this problem.
2. Later on, I realize the mistake and find that I can use the **stack** to solve it!

