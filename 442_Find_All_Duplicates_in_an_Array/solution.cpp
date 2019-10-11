class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int val;
        for(int i = 0; i < nums.size(); i++){
            val = nums[i];
            while(i+1 != val && val >= 0){
                if(val == nums[val-1]){
                    ret.push_back(val);
                    nums[i] = -1;
                    break;
                }
                swap(nums[val-1], nums[i]);
                val = nums[i];
            }
        }
        return ret;
    }
};