class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret = {{}};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int size = ret.size(), start = 0;
            if(i > 0 and nums[i] == nums[i-1])
                start = old_size;
            for(int j = start; j < size; j++){
                vector<int> path = ret[j];
                path.push_back(nums[i]);
                ret.push_back(path);
            }
            old_size = size;
        }
        return ret;
    }
private:
    int old_size = 0;
};