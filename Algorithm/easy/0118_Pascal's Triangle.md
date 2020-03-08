Description
--
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

Example
--
Input: 5
Output:
```
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

cpp solutions 
---
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        for (int i = 0; i < numRows; ++i) {
            v[i].resize(i+1,1);
            for (int j = 1; j < i; ++j) {
                v[i][j] = v[i-1][j-1] + v[i-1][j];
            }
        }
        return v;
    }
};
```

Some Ideas
--
Be familiar with the `resize` syntax.
