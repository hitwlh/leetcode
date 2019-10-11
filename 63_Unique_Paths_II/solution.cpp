class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() or obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> ret(n, 0);
        for(int i = 0; i < n; i++){
            if(!obstacleGrid[0][i]) ret[i] = 1;
            else break;
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!obstacleGrid[i][j])
                    ret[j] += ret[j-1];
                else ret[j] = 0;
            }
        }
        return ret.back();
    }
};