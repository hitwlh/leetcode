class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> gr(nums.size());
        int len = 0;
        gr[len++] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < gr[0]) gr[0] = nums[i];
            else if(nums[i] > gr[len-1]) gr[len++] = nums[i];
            else{
                int it = find(gr, len, nums[i]);
                gr[it] = nums[i];
            }
        }
        return len;
    }
private:
    int find(vector<int>& gr, int len, int target){
        int left = 0, right = len-1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(gr[mid] < target) left = mid + 1;
            else right = mid;
        }
        if(gr[left] >= target) return left;
        return -1;
        //严格说起来这里要判断left是否满足的，也就是要防止序列最后一个元素仍然小于target。
        //但是这题倒是不用担心，因为函数外部已经保证序列里有大于等于target的元素
    }
};