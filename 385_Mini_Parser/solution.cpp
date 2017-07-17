/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger ret;
        stack<string> sta;
        if(s == "[]") return ret;
        int now = s.length()-1;
        if(s[now] != ']'){
            ret.setInteger(atoi(s.c_str()));
            return ret;
        }
        int next;
        while(now > 0){
            if(s[now-1] == ']'){
                next = find(s, now-1, '[');
                sta.push(s.substr(next, now - next));
                now = next - 1;
            }else{
                next = find(s, now-1, ',');
                if(next == -1){
                    sta.push(s.substr(1, now - 1));
                    now = next;
                }else{
                    sta.push(s.substr(next+1, now - next - 1));
                    now = next;
                }
            }
        }
        stack<string> debug = sta;
        while(!sta.empty()){
            string top = sta.top();
            sta.pop();
            ret.add(deserialize(top));
        }
        return ret;
    }
private:
    int find(string &s, int start, char find){
        if(find == ','){
            for(int i = start-1; i >= 0; i--)
                if(s[i] == find) return i;
            return -1;
        }
        int num = 0;
        for(int i = start - 1; i >= 0; i--){
            if(s[i] == ']') num++;
            if(s[i] == '[') num--;
            if(num < 0) return i;
        }
        return -1;
    }
};