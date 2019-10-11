class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret = {{}};
        for(int i = 0; i < nums.size(); i++){
            int size = ret.size();
            for(int j = 0; j < size; j++){
                vector<int> push = ret[j];
                push.push_back(nums[i]);
                ret.push_back(push);
            }
        }
        return ret;
    }
};