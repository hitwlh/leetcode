class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int conse = 0, maxC = INT_MIN;
        if(nums.empty()) return 0;
        if(nums[0] == 1) maxC = conse = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]==1) conse++;
            else{
                if(conse > maxC) maxC = conse;
                conse = 0;
            }
        }
        if(conse > maxC) maxC = conse;
        return maxC;
    }
};