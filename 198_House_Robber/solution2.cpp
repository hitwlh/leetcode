class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        steal.assign(nums.size(), 0);
        notsteal.assign(nums.size(), 0);
        steal[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            notsteal[i] = max(steal[i-1], notsteal[i-1]);
            steal[i] = max(notsteal[i-1] + nums[i], steal[i-1]);
        }
        return steal[nums.size()-1];
    }
private:
    vector<int> steal,notsteal;
};