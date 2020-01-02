Description
--
Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.
You may assume that each input would have **exactly** one solution, and you may not use the same element twice.

Example
--
Given nums = [2, 7, 11, 15], target = 9. Because nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].

cpp solutions
--
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for (size_t i=0; i<nums.size();++i){
            m[nums[i]] = i;
        }
        vector<int> result;
        for (size_t i=0; i<nums.size();++i){
            auto it = m.find(target-nums[i]);
            if(it!=m.end() && it->second!=i){
                result.push_back(i);
                result.push_back(it->second);
                return result;
            }
        }
        return result;
    }
};
```
