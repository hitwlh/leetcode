class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, multiset<string>> mymap;
        for(auto i: tickets)
            mymap[i.first].insert(i.second);
        vector<string> ret;
        stack<string> sta;
        sta.push("JFK");
        while(!sta.empty()){
            string up = sta.top();
            if(mymap.find(up) != mymap.end() && mymap[up].size()){
                sta.push(*(mymap[up].begin()));
                mymap[up].erase(mymap[up].begin());
            }else{
                ret.insert(ret.begin(), up);
                sta.pop();
            }
        }
        return ret;
    }
};