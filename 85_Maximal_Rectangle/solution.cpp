class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
        //really important
            return 0;
        if(matrix[0].empty())
            return 0;
        vector<int> len(matrix[0].size(), 0);
        int ma = 0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]=='1')
                    len[j] += 1;
                else
                    len[j] = 0;
            }
            int ret = largestRectangleArea(len);
            ma = ma>ret?ma:ret;
        }
        return ma;
    }
private:
    int largestRectangleArea(vector<int> heights) {
        if(heights.empty())
            return 0;
        int ma = 0;
        heights.push_back(0);
        std::stack<int> first;
        std::stack<int> second;
        first.push(0);
        second.push(-1);
        for(int i=0;i<heights.size();i++){
            if(first.top()<=heights[i]){
                first.push(heights[i]);
                second.push(i);
            }
            else{
                while(!first.empty()&&first.top()>heights[i]){
                    int leg = first.top();
                    first.pop();
                    second.pop();
                    int left_index = second.top();
                    int right_index = i;
                    int area = (right_index - left_index - 1) * leg;
                    ma = ma>area?ma:area;
                }
                first.push(heights[i]);
                second.push(i);
            }
        }
        return ma;
    }
};