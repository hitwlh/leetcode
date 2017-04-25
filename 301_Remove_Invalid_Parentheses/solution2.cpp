//安排了两个queue，是因为要reverse之后处理'('非法的情况
//bfs传入notempty表示这个queue里是有内容的(备选解)，然后如果queue里string的针对c合法，那就把它push到另外一个queue里头去，如果非法，那就找到备选解后push到queue里
//注意：如果从左到右找到一个非法位置，那就把这个非法位置的左侧所有')'删一个，生成备选解，所生成的备选解(若干个)要push进队列，然后要break，这才符合意思。如果不break，直接一直往后去找新的非法的')'了，完全不合意思
//先用')'，讲')'合法的所有字符以及上一步删的位置push到useful[1]，然后在调用bfs，从useful[1]将'('合法的写到useful[0]
//useful[0]里头就是答案了，把答案全部写到ret里，返回就ok了

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        useful[0].push({s, 0});
        bfs(0, ')');
        bfs(1, '(');
        while(!useful[0].empty()){
            ret.push_back(useful[0].front().first);
            useful[0].pop();
        }
        return ret;
    }
private:
    void bfs(int notempty, char c){
        while(!useful[notempty].empty()){
            int ch = 0;
            string s = useful[notempty].front().first;
            int last = useful[notempty].front().second;
            useful[notempty].pop();
            bool flag = true;
            for(int i = 0; i < s.length(); i++){
                if(s[i] != '(' && s[i] != ')') continue;
                s[i] == c ? ch++ : ch--;
                if(ch <= 0) continue;
                flag = false;
                for(int j = last; j <= i; j++){
                    if(s[j] == c  && (j == last || s[j-1] != c)){
                        useful[notempty].push({s.substr(0, j) + s.substr(j+1), j});
                    }
                }
                break;
            }
            if(flag){
                reverse(s.begin(), s.end());
                useful[1-notempty].push({s, 0});
            }
        }
    }
    queue<pair<string, int>> useful[2];
    vector<string> ret;
};