#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ma = 0;
        heights.push_back(0);
        stack<int> mysta;
        mysta.push(-1);
        for(int i = 0; i < heights.size(); i++){
            if(mysta.top() == -1 or heights[mysta.top()] > heights[i]){
                while(!mysta.empty() && mysta.top() != -1 and heights[mysta.top()] > heights[i]){
                    int leg = heights[mysta.top()];//当前大矩形高度
                    mysta.pop();
                    int left_index = mysta.top(), right_index = i;
                    int width = right_index - left_index - 1;
                    cout << "left_index is: " << left_index << ", right_index is: " << right_index << ", width is: " << width << ", height is: " << leg << endl;
                    int area = width * leg;//left_index右侧的小矩形，高度均大于leg；right_index左侧的小矩形，高度均大于leg。因此宽度为right_index - left_index - 1
                    ma = max(area, ma);
                }
            }
            mysta.push(i);
        }
        return ma;
    }
};

int main(){
  Solution s;
  vector<int> height;
  height.push_back(1);
  height.push_back(3);
  height.push_back(4);
  height.push_back(2);
  cout << s.largestRectangleArea(height) << endl;
  return 0;
}