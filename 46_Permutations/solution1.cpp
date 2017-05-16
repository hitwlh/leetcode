class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
                swap(nums[i], nums[next]);
                perm(nums, i+1);
                swap(nums[i], nums[next]);
            }
        }
    }
};






class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
                //swap(nums[i], nums[next]);
                nums.insert(nums.begin() + i, nums[next]);
                nums.erase(nums.begin() + next + 1);
                perm(nums, i+1);
                nums.insert(nums.begin() + next + 1, nums[i]);
                nums.erase(nums.begin() + i);
                //swap(nums[i], nums[next]);
            }
        }
    }
};