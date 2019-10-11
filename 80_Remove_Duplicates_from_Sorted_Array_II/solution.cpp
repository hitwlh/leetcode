class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int now = 0, next;
        while(now+2 < nums.size()){
            while(now+2 < nums.size() && nums[now] == nums[now+2]) nums.erase(nums.begin()+now+2);
            if(now+2 >= nums.size()) return nums.size();
            if(nums[now] == nums[now+1]) now += 2;
            else now ++;
        } 
        return nums.size();
    }
};