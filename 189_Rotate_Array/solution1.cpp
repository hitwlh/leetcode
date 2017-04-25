class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int idx = 0, distance = 0, cur = nums[0];
        for(int x = 0; x < n; x++){
            idx = (idx + k) % n;
            swap(nums[idx], cur);
            distance = (distance + k) % n;
            if(distance == 0){
                idx = (idx + 1) % n;
                cur = nums[idx];
            }
        }
    }
};