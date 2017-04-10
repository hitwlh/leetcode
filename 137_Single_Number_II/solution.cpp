class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<sizeof(int)*8;i++){
            int times = 0;
            for(int j=0;j<nums.size();j++){
                if((nums[j]>>i)&1)
                    times++;
            }
            if(times%3){
                res |= 1<<i;
            }
        }
        return res;
    }
};