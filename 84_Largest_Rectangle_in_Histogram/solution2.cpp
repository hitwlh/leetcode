class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
private: void show_stack(std::stack<int> &first)
{
    std::stack<int> second;
    int x;
    while(!first.empty()){
        x = first.top();
        cout << x << " " ;
        first.pop();
        second.push(x);
    }
    while(!second.empty()){
        x = second.top();
        second.pop();
        first.push(x);
    }
}
};