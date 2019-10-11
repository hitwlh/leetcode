class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2, less_times = 0, big_times = 0, equl_times = 0;
            for(auto i: nums){
                if(i == mid) equl_times++;
                else if(i < mid) less_times++;
                else big_times++;
            }
            if(equl_times > 1) return mid;
            if(big_times > (nums.size() - 1 - mid)) left = mid + 1;
            //注意这里要用nums.size() - 1 - mid，一开始直接对比big_times和less_times错了
            //因为如果中位数有2个时，无法判断是落在左侧还是右侧
            else right = mid - 1;
        }
    }
};