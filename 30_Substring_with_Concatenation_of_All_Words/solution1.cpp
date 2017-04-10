class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        std::priority_queue<int> results;
        std::priority_queue<int> tmp;
        if(words.empty()) return ret;
        map<string, int> my_map;
        int length = words[0].length();
        for(int i = 0; i<words.size(); i++){
            if(my_map.count(words[i]) > 0);
            else my_map[words[i]] = i+1;
            results.push(my_map[words[i]]);
        }
        int total_length = length * words.size();
        int *index = new int[s.length()];
        memset(index, 0, sizeof(int) * s.length());
        for(int i = 0 ; i+length <= s.length(); i++){
            if(my_map.count(s.substr(i, length)) > 0)
                index[i] = my_map[s.substr(i, length)];
        }
        int sum = 0;
        int size = words.size();
        for(int i = 0 ; i+total_length <= s.length(); i++){
            int j = i;
            size = words.size();
            tmp.push(index[j]);
            while(--size){
                j+= length;
                tmp.push(index[j]);
            }
            if(equal(results,tmp))
                ret.push_back(i);
            while(!tmp.empty())
                tmp.pop();
        }
        return ret;
    }
private:
    bool equal(std::priority_queue<int> results, std::priority_queue<int> tmp){
        while(!results.empty() && !tmp.empty()){
            if(results.top() != tmp.top())
                return false;
            results.pop();
            tmp.pop();
        }
        return true;
    }
};