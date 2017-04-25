class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int tmp1, tmp2;
        for(int i = 0; i < nums.size(); i++){
            tmp1 = nums[i];
            tmp2 = tmp1-1;
            while(tmp1 != nums[tmp2]){
                tmp2 = nums[tmp1-1];
                nums[tmp1-1] = tmp1;
                tmp1 = tmp2;
                tmp2--;
            }
        }
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != i+1)
                ret.push_back(i+1);
        return ret;
    }
};