class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            if(height[i] < height[j]){
                area = max(area, height[i] * (j-i));
                i++;
            }
            else{
                area = max(area, height[j] * (j-i));
                j--;
            }
        }
        return area;
    }
};