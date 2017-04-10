class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> first;
        for(int i=0;i<nums.size();i++)
            first[nums[i]] = i;
        for(int i=0;i<nums.size();i++)
            if(first.find(target-nums[i])!=first.end()&&i!=first[target-nums[i]])
                return {i,first[target-nums[i]]};
    }
};
