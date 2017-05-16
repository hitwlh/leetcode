class NumArray {
public:
    NumArray(vector<int> nums) {
        if(nums.empty()) return;
        my_nums.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
            my_nums.push_back(my_nums[my_nums.size()-1] + nums[i]);
    }
    
    int sumRange(int i, int j) {
        if(!i) return my_nums[j];
        return my_nums[j] - my_nums[i-1];
    }
private:
    vector<int> my_nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */