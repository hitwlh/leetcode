class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_MAX(height.size()+1, 0), right_MAX(height.size()+1, 0);
        for(int i = 0; i < height.size(); i++)
            left_MAX[i+1] = max(left_MAX[i], height[i]);
        for(int i = height.size()-1; i >= 0; i--)
            right_MAX[i] = max(right_MAX[i+1], height[i]);
        int ret = 0;
        for(int i = 0; i< height.size(); i++)
            ret += min(left_MAX[i+1], right_MAX[i]) - height[i];
        return ret;
    }
};