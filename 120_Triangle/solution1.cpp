class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty() || triangle[0].empty()) return 0;
        for(int i = triangle.size() - 1; i > 0 ; i--){
            for(int j = 0; j < triangle[i-1].size(); j++){
                int MIN = INT_MAX;
                if(j >= 0 && j < triangle[i].size()) MIN = min(MIN, triangle[i][j]);
                if(j+1 >= 0 && j+1 < triangle[i].size()) MIN = min(MIN, triangle[i][j+1]);
                triangle[i-1][j] = triangle[i-1][j] + MIN;
            }
        }
        return triangle[0][0];
    }
};