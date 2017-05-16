class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() + 1 - k;
        priority_queue<int> mypq;//小根堆
        for(int i = 0; i < k; i++) mypq.push(nums[i]);
        for(int i = k; i < nums.size(); i++){
            if(nums[i] >= mypq.top());
            else{
                mypq.push(nums[i]);
                mypq.pop();
            }
        }
        return mypq.top();
    }
};