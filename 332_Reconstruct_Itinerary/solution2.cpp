class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto i: tickets){
            selection[i.first].push_back(i.second);
            used[{i.first, i.second}]++;
        }
        for(auto &i: selection) sort(i.second.begin(), i.second.end());
        string now = "JFK";
        dfs(tickets.size(), now);
        reverse(ret.begin(), ret.end());
        return ret;
    }
private:
    vector<string> ret;
    map<string, vector<string>> selection;
    map<pair<string, string>, int> used;
    bool dfs(int num, string now){
        if(num == 0){
            ret.push_back(now);
            return true;
        }
        for(int i = 0; i < selection[now].size(); i++){
            if(used[{now, selection[now][i]}] != 0){
                used[{now, selection[now][i]}] -- ;
                if(dfs(num-1,selection[now][i])){
                    ret.push_back(now);
                    return true;
                }
                used[{now, selection[now][i]}]++;
            }
        }
        return false;
    }
};