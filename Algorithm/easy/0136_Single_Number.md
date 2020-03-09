Description
--

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example
--

```
Input: [2,2,1]
Output: 1
```

```
Input: [4,1,2,1,2]
Output: 4
```

cpp solutions
---

#### Hash Table using unordered_map

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        for (auto itt = m.begin();itt!=m.end(); ++itt){
            if (itt->second == 1) return itt->first;
        }
        return 0;
    }
};
```

#### Hash Table using [unordered_set](https://leetcode.com/problems/single-number/discuss/250565/c%2B%2B-unordered_set)

```cpp
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int> s;
		for (int i = 0; i < nums.size(); i++) {
			if (s.find(nums[i]) != s.end()) {
                s.erase(nums[i]);
            }
			else {
				s.insert(nums[i]);
			}
		}
		return *s.begin();
	}
};
```

#### Bitwise operation using [XOR](https://leetcode.com/problems/single-number/discuss/350206/Solution-CPP-or-Using-XOR-operation)

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int temp =0;
        for(int i=0; i < n; i++)
            temp ^= nums[i];
        return temp;
    }
};
```


Some Ideas
--

XOR is amazing...Note that A XOR A = 0, 0 XOR B = B
