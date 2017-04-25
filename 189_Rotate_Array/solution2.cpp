class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()) return ;
        k %= nums.size();
        reverse(nums, 0, nums.size());
        reverse(nums, 0, k);
        reverse(nums, k, nums.size());
    }
private:
    void reverse(vector<int>& nums, int start, int end){
        for(int i = start; i < (end+start)/2; i++)
            swap(nums[i], nums[end-1+start-i]);
    }
};