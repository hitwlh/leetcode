class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        if(nums.empty()) return ret;
        stack<int> sta;
        for(int i = nums.size() - 1; i >= 0; i--)
            sta.push(nums[i]);
        for(int i = nums.size() - 1; i >= 0; i--){
            while(!sta.empty() && sta.top() <= nums[i]) sta.pop();
            if(!sta.empty()) ret[i] = sta.top();
            else ret[i] = -1;
            sta.push(nums[i]);
        }
        return ret;
    }
};