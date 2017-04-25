class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty() || triangle[0].empty())
            return 0;
        int size = triangle.size();
        vector<int> mv(triangle[size-1]);
        //mv.assign(size, 0);
        for(int i = size - 2; i >= 0 ; i--){
            for(int j = 0; j < mv.size() && j < triangle[i].size(); j++){
                int MIN = INT_MAX;
                if(j >= 0 && j < mv.size()) MIN = min(MIN, mv[j]);
                if(j+1 >= 0 && j+1 < mv.size()) MIN = min(MIN, mv[j+1]);
                mv[j] = triangle[i][j] + MIN;
            }
        }
        return mv[0];
    }
};