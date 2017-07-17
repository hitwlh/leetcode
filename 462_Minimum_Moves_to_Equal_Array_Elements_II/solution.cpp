class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size() <=1 ) return 0;
        sort(nums.begin(), nums.end());
        vector<long long> left(nums.size(), 0), right(nums.size(), 0), num(nums.size(), 0);
        //left[i]表示nums[i]左侧所有数字变成nums[i]所需要的moves，所以从left[1]开始(left[0]=0)
        //;right[i]表示nums[i]右侧所有数字变成nums[i]所需要的moves，所以从right[left.size()-2]开始;(right[right.size()-2]=0)
        for(int i = 0; i < nums.size(); i++)
            num[i] = nums[i];
        for(int i = 1; i < nums.size(); i++)
            left[i] = i * (num[i] - num[i-1]) + left[i-1];
        for(int i = nums.size()-2; i >= 0; i--)
            right[i] = (num.size() - 1 - i) * (num[i+1] - num[i]) + right[i+1];
        long long MIN = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
            MIN = min(left[i] + right[i], MIN);
        return MIN;
    }
};