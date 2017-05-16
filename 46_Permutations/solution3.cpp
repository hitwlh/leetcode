class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> use;
        vector<vector<int>> ret({{nums[0]}});
        for(int i = 1; i < nums.size(); i++){
            int old_size = ret[0].size();
            while(ret[0].size() == old_size){
                use = ret[0];
                ret.erase(ret.begin());
                for(int j = 0; j <= use.size(); j++){
                    use.insert(use.begin() + j, nums[i]);
                    ret.push_back(use);
                    use.erase(use.begin() + j);
                }
            }
        }
        return ret;
    }
};