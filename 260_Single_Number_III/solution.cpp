class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i=0;i<nums.size();i++){
            ret ^= nums[i];
        }
        int devi = 1;
        while((ret&1)==0){
            ret = ret>>1;
            devi = devi<<1;
        }
        int ret1=0,ret2=0;
        if(devi){
            for(int i=0;i<nums.size();i++){
            if(nums[i]&devi){
                ret1 ^= nums[i];
            }
            else{
                ret2 ^= nums[i];
            }
            }
        }
        return {ret1,ret2};
    }
};