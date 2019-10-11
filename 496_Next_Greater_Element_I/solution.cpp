class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int, int> mymap;
        stack<int> sta;
        for(int i = nums.size() - 1; i>= 0; i--){
            while(!sta.empty() && sta.top() <= nums[i])
                sta.pop();
            if(sta.empty())
                mymap[nums[i]] = -1;
            else
                mymap[nums[i]] = sta.top();
            sta.push(nums[i]);
        }
        vector<int> ret;
        for(auto i: findNums) ret.push_back(mymap[i]);
        return ret;
    }
};