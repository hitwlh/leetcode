class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int ret1, ret2;
        steal.assign(nums.size(), 0);
        notsteal.assign(nums.size(), 0);
        steal[1] = nums[1];
        for(int i = 2; i < nums.size(); i++){
            notsteal[i] = max(steal[i-1], notsteal[i-1]);
            steal[i] = max(notsteal[i-1] + nums[i], steal[i-1]);
        }
        ret1 = steal[nums.size()-1];
        steal.assign(nums.size(), 0);
        notsteal.assign(nums.size(), 0);
        steal[0] = nums[0];
        for(int i = 1; i+1 < nums.size(); i++){
            notsteal[i] = max(steal[i-1], notsteal[i-1]);
            steal[i] = max(notsteal[i-1] + nums[i], steal[i-1]);
        }
        ret2 = steal[nums.size()-2];
        return max(ret1, ret2);
    }
private:
    vector<int> steal,notsteal;
};