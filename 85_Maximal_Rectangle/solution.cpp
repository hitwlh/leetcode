class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() or matrix[0].empty())
        //really important
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
            ma = max(largestRectangleArea(len), ma);
        }
        return ma;
    }
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> index;
        index.push(-1);
        int ret = 0;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++){
            while(!index.empty() and index.top() != -1 and heights[index.top()] >= heights[i]){
                int height = heights[index.top()];//当前大矩形高度
                index.pop();//这里的pop非常有意思：若当前栈顶的位置index1的高度是h，当pop掉之后，栈顶是上一个低于h的高度的index2，介于index1 与index2之间如果有高于h的条带，就这样利用上了 。
                int width = i - index.top() - 1;
                //left_index(不包括left_index,因为正确高度的栈顶已被弹出，当前栈顶的高度是严格小于上一个栈顶的)右侧的小矩形，高度均大于leg；
                //right_index左侧的小矩形，高度均大于leg。因此宽度为right_index - left_index - 1
                ret = max(ret, width * height);
            }
            index.push(i);
        }
        return ret;
    }
};