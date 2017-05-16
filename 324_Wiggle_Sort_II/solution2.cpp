class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int mid = nums.size() / 2;
        nth_element (nums.begin(), nums.begin() + mid, nums.end());
        int value = nums[mid];
        int left = 0, now = 0, right = nums.size()-1;
        while(now <= right){
            if(nums[now] < value){
                swap(nums[left], nums[now]);
                left++;
                now++;
            }else if(nums[now] == value)
                now++;
            else{
                swap(nums[right], nums[now]);
                right--;
            }
        }
        left = (nums.size()-1)/2, right = nums.size()-1, now = 0;
        vector<int> use = nums;
        while(left >= 0){
            nums[now++] = use[left--];
            if(right > (nums.size()-1)/2)
                nums[now++] = use[right--];
        }
    }
};