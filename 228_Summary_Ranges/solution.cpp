class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if(nums.empty()) return ret;
        int left = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(i + 1 == nums.size() || nums[i+1] != nums[i] + 1){
                if(left != nums[i])
                    ret.push_back(to_string(left) + "->" + to_string(nums[i]));
                else
                    ret.push_back(to_string(left));
                if(i + 1 != nums.size())
                    left = nums[i+1];
            }
        }
        return ret;
    }
};