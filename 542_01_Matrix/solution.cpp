class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        ret = matrix;
        for(int i = 0; i < ret.size(); i++)
            for(int j = 0; j < ret[i].size(); j++)
                if(ret[i][j] == 1) ret[i][j] = -1;
        int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for(int i = 0; i < ret.size(); i++)
            for(int j = 0; j < ret[i].size(); j++)
                if(ret[i][j] == 0)
                    index.push({i, j});
        index.push({-1, -1});
        int now = 1;
        while(!index.empty()){
            if(index.front().first == -1 && index.front().second == -1){
                now++;
                index.pop();
                if(!index.empty())
                    index.push({-1, -1});
                continue;
            }
            for(int i = 0; i < 4; i++){
                if(isvalid(index.front().first + direction[i][0], index.front().second + direction[i][1])){
                    if(ret[index.front().first + direction[i][0]][index.front().second + direction[i][1]] == -1){
                        ret[index.front().first + direction[i][0]][index.front().second + direction[i][1]] = now;
                        index.push({index.front().first + direction[i][0], index.front().second + direction[i][1]});
                    }
                }
            }
            index.pop();
        }
        return ret;
    }
private:
    vector<vector<int>> ret;
    queue<pair<int, int>> index;
    bool isvalid(int i, int j){
        return i >= 0 && i < ret.size() && j >= 0 && j < ret[i].size();
    }
};