class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        vector<vector<int>> path;
        vector<int> tmp;
        tmp.assign(obstacleGrid[0].size(), 0);
        path.assign(obstacleGrid.size(), tmp);
        if(obstacleGrid[0][0] == 0) path[0][0] = 1;
        else return 0;
        int i;
        for(i = 0; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0] == 0) path[i][0] = 1;
            else break;
        }
        for(i = 0; i < obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i] == 0) path[0][i] = 1;
            else break;
        }
        for(int i = 1; i < obstacleGrid.size(); i++){
            for(int j = 1; j < obstacleGrid[i].size(); j++){
                if(obstacleGrid[i][j] == 1) continue;
                if(path[i][j-1] > 0) path[i][j] += path[i][j-1];
                if(path[i-1][j] > 0) path[i][j] += path[i-1][j];
            }
        }
        return path[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};