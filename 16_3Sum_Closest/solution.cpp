class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int left = target-1;
        int right = target+1;
        sort(nums.begin(), nums.end());
        if(threeSum(nums, target)) return target;
        while(true){
            if(threeSum(nums, left)) return left;
            left--;
            if(threeSum(nums, right)) return right;
            right++;
        }
    }
private:
    bool threeSum(vector<int>& nums, int targets) {
        if(nums.size() < 3)
            return false;
        for(int k = 0; k<=nums.size() - 3; k++){
            if(k>0 && nums[k] == nums[k-1]) continue;
            //注意这里非常重要！！！
            int target = targets - nums[k];
            int i= k+1, j = nums.size()-1;
            while(i < j){
                if(nums[i] + nums[j] == target)
                    return true;
                else if(nums[i] + nums[j] < target) i++;
                else j--;
            }
        }
        return false;
    }
};