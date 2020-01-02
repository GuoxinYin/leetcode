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
