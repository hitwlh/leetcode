class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> numb(nums.size(), 1);
        int n = nums.size();
        for(int i = n - 2; i >= 0; i--){
            int MAX = 0;
            for(int j = i + 1; j < n; j++){
                if(nums[j] > nums[i])
                    MAX = max(MAX, numb[j]);
            }
            numb[i] = MAX + 1;
        }
        int MAX = 0;
        for(auto i: numb) MAX = max(MAX, i);
        return MAX;
    }
};