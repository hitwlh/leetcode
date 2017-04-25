class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()){
            vector<pair<int, int>> empty;
            return empty;
        }
        my_matrix = matrix;
        vector<int> tmp;
        tmp.assign(my_matrix[0].size(), 0);
        visit.assign(my_matrix.size(), tmp);
        jilu1.assign(my_matrix.size(), tmp);
        jilu2.assign(my_matrix.size(), tmp);
        queue<pair<int, int>> index;
        for(int i = 0; i < my_matrix.size(); i++){
            visit[i][0] = 1;
            jilu1[i][0] = 1;
            index.push({i, 0});
        }
        for(int i = 1; i < my_matrix[0].size(); i++){
            visit[0][i] = 1;
            jilu1[0][i] = 1;
            index.push({0, i});
        }
        int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!index.empty()){
            int first = index.front().first, second = index.front().second;
            for(int i = 0; i < 4; i++){
                if(isvalid(first + direction[i][0], second + direction[i][1]) && my_matrix[first][second] <= my_matrix[first + direction[i][0]][second + direction[i][1]] && visit[first + direction[i][0]][second + direction[i][1]]== 0){
                    visit[first + direction[i][0]][second + direction[i][1]] = 1;
                    jilu1[first + direction[i][0]][second + direction[i][1]] = 1;
                    index.push({first + direction[i][0], second + direction[i][1]});
                }
            }
            index.pop();
        }
        visit.assign(my_matrix.size(), tmp);
        for(int i = 0; i < my_matrix.size(); i++){
            visit[i][my_matrix[i].size()-1] = 1;
            jilu2[i][my_matrix[i].size()-1] = 1;
            index.push({i, my_matrix[i].size()-1});
        }
        for(int i = 0; i < my_matrix[0].size(); i++){
            visit[my_matrix.size()-1][i] = 1;
            jilu2[my_matrix.size()-1][i] = 1;
            index.push({my_matrix.size()-1, i});
        }
        while(!index.empty()){
            int first = index.front().first, second = index.front().second;
            for(int i = 0; i < 4; i++){
                if(isvalid(first + direction[i][0], second + direction[i][1]) && my_matrix[first][second] <= my_matrix[first + direction[i][0]][second + direction[i][1]] && visit[first + direction[i][0]][second + direction[i][1]]== 0){
                    visit[first + direction[i][0]][second + direction[i][1]] = 1;
                    jilu2[first + direction[i][0]][second + direction[i][1]] = 1;
                    index.push({first + direction[i][0], second + direction[i][1]});
                }
            }
            index.pop();
        }
        vector<pair<int, int>> ret;
        for(int i = 0; i < jilu1.size(); i++){
            for(int j = 0; j < jilu1[i].size(); j++){
                if(jilu1[i][j] && jilu2[i][j]) ret.push_back({i, j});
            }
        }
        return ret;
    }
private:
    vector<vector<int>> my_matrix, jilu1, jilu2, visit;
    bool isvalid(int i, int j){
        return i >= 0 && i < my_matrix.size() && j >= 0 && j < my_matrix[0].size();
    }
};