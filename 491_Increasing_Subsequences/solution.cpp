class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.empty()) return ret;
        my_nums = nums;
        dfs(-1, {-101});
        for(auto i: firstr) ret.push_back(i);
        return ret;
    }
private:
    void dfs(int index, vector<int> value){
        int num = value[value.size()-1];
        if(index+1 >= my_nums.size())
            return;
        if(my_nums[index+1] >= num){
            value.push_back(my_nums[index+1]);
            vector<int> puh(value.begin()+1, value.end());
            if(puh.size() > 1)
                firstr.insert(puh);
            dfs(index+1, value);
            value.pop_back();
        }
        dfs(index+1, value);
    }
    set<vector<int>> firstr;
    vector<vector<int>> ret;
    vector<int> my_nums;
};