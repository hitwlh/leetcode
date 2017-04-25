class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;
        vector<int> left, right;
        left.assign(height.size(), 0);
        right.assign(height.size(), 0);
        int MAX = 0;
        right[height.size() - 1] = 0;
        for(int i = height.size() - 2; i >= 0; i--){
            right[i] = max(MAX, height[i+1]);
            MAX = right[i];
        }
        left[0] = 0; MAX = 0;
        for(int i = 1; i < height.size()-1; i++){
            left[i] = max(MAX, height[i-1]);
            MAX = left[i];
        }
        int ret = 0;
        for(int i = 0; i < height.size()-1; i++)
            ret += max(min(left[i] - height[i], right[i] - height[i]), 0);
        return ret;
    }
};