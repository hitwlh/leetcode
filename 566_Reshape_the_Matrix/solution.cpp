class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int size1 = nums.size(), size2 = 0;
        if(size1) size2 = nums[0].size();
        if(size1 * size2 != r * c) return nums;
        vector<vector<int>> ret(r,vector<int> (c,0));
        for(int i = 0; i < r * c; i++)
            ret[i/c][i%c] = nums[i/size2][i%size2];
        return ret;
    }
};