class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> use = nums;
        sort(use.begin(), use.end());
        int left = (nums.size()-1)/2, right = nums.size()-1, now = 0;
        while(left >= 0){
            nums[now++] = use[left--];
            if(right > (nums.size()-1)/2)
                nums[now++] = use[right--];
        }
    }
};