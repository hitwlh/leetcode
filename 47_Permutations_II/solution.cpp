class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        perm(nums, 0);
        return ret;
    }
private:
    vector<vector<int>> ret;
    void perm(vector<int>& nums, int i){
        if(i >= nums.size()){
            ret.push_back(nums);
        }else{
            for(int next = i; next < nums.size(); next++){
                if(next == i || nums[next-1] != nums[next]){
                    swap(nums[i], nums[next]);
                    perm(nums, i+1);
                    swap(nums[i], nums[next]);
                }
            }
        }
    }
};

