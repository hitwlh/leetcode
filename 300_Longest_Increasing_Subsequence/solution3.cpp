class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size(), len = 0;
        if(!size) return 0;
        vector<int> gt(1, nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= gt[0]) gt[0] = nums[i];
            else if(nums[i] > gt.back()) gt.push_back(nums[i]);
            else{
                int left = 0, right = gt.size()-1;
                while(left <= right){
                    int mid = left + (right - left) / 2;
                    if(gt[mid] >= nums[i]) right = mid-1;
                    else left = mid+1;
                }
                gt[right+1] = nums[i];
            }
        }
        return gt.size();
    }
};