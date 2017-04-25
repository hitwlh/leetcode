class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int now = 0, flag = 0, ret = 0;
        while(now <= nums.size() - 2){
            if((flag == 1 || flag == 0) && nums[now+1] > nums[now]){
                int next = now+2;
                while(next < nums.size() && nums[next] > nums[next-1]) next++;
                ret++;
                now = next-1;
                flag = -1;
            }else if((flag == -1 || flag == 0) && nums[now+1] < nums[now]){
                int next = now+2;
                while(next < nums.size() && nums[next] < nums[next-1]) next++;
                ret++;
                now = next-1;
                flag = 1;
            }else now++;
        }
        return ret+1;
    }
};