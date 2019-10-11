class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        perm(nums, 0);
        return ret;
    }
private:
    vector<vector<int>> ret;
    void perm(vector<int>& nums, int i){
        if(i >= nums.size())
            ret.push_back(nums);
        for(int next = i; next < nums.size(); next++){
            if(i == next || nums[next] != nums[next-1]){
                nums.insert(nums.begin() + i, nums[next]);
                nums.erase(nums.begin() + next + 1);
                perm(nums, i+1);
                nums.insert(nums.begin() + next + 1, nums[i]);
                nums.erase(nums.begin() + i);
            }
        }
    }
};