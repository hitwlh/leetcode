class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return 0;
        int i = 0, j = height.size() - 1, result = 0;
        while(i < j){
            result = max((j - i) * min(height[j], height[i]), result);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return result;
    }
};