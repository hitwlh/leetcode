class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> index;
        int left = 0;
        int ret = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                index.push(i);
            else{
                if(index.empty())
                    left = i+1;
                else{
                    index.pop();
                    if(index.empty())
                        ret = max(ret, i-left+1);
                    else
                        ret = max(ret, i-index.top());
                }
            }
        }
        return ret;
    }
};