class Solution {
public:
    vector<string> generateParenthesis(int n) {
        my_gen(n, n, "");
        return ret;
    }
private:
    vector<string> ret;
    void my_gen(int left, int right, string s)//left代表可以画left个'(', right代表可以画left个')'
    {
        if(left > 0)
            my_gen(left - 1, right, s+'(');
        if(right > 0 && left < right)
            my_gen(left, right-1, s+')');
        if(left == 0 && right  == 0)
            ret.push_back(s);
    }
};