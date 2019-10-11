class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto a : tickets) {
            m[a.first].insert(a.second);
        }
        dfs("JFK");
        return vector<string> (res.rbegin(), res.rend());
    }
private:
    unordered_map<string, multiset<string>> m;
    vector<string> res;
    void dfs(string s) {
        while (m[s].size()) {
            string t = *m[s].begin();
            m[s].erase(m[s].begin());
            dfs(t);//dfs即可求解出t，题目规定了一定有解，因此s的下一站，全部递归，一定有一个是解，在push出s就是了
        }
        res.push_back(s);
    }
};