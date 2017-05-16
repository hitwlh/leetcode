class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start = 0, slow = 0, fast = 0;
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(slow != fast);
        while(start != slow){
            slow = nums[slow];
            start = nums[start];
        }
        return slow;
    }
};