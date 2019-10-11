class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        if(nums.empty())
            return ret;
        int num0, num1;
        int count0 = 0;
        int count1 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(num1 != nums[i] && count0 == 0){
            //注意这里要判断num1 != nums[i]
            //因为如果是进行到后面，抵消完所有num1，没抵消完num2，则下一个元素可能和nums相等
            //really important
               num0 = nums[i];
               count0 = 1;
            }
            else if(num0 != nums[i] && count1 == 0){
                num1 = nums[i];
                count1 = 1;
            }
            else if(num0 == nums[i]){
                count0 ++;
            }
            else if(num1 == nums[i]){
                count1 ++;
            }
            else{
                count0 --;
                count1 --;
            }
        }
        if(count0 && IsMajority(num0, nums))
            ret.push_back(num0);
        if(count1 && IsMajority(num1, nums))
            ret.push_back(num1);
        return ret;
    }
private:
    bool IsMajority(int num, vector<int>& nums){
        int count = 0;
        for(int i=0;i<nums.size(); i++){
            if(num ==  nums[i])
                count ++;
        }
        if(count > nums.size()/3)
            return true;
        return false;
    }
};