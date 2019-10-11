class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), s2 = INT_MIN;
        stack<int> sta;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] < s2) return true;
            while(!sta.empty() && sta.top() < nums[i]){
                s2 = sta.top();
                sta.pop();
            }
            sta.push(nums[i]);
        }
        return false;
    }
};