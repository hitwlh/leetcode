class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty() ) return res;
        int n = words.size(), m = words[0].size();
        unordered_map<string, int> m1, m2;
        for (auto &a : words) ++m2[a];
        int left_index, right_index;
        int length = s.length();
        for(int i = 0; i < words[0].size(); i++){
            m1 = m2;//m1[s] = j,代表字符串s还需要匹配j次
            left_index = i;
            right_index = i;
            while(right_index <= length - m ){
                if(left_index <= right_index){
                    if((right_index - left_index) / m == n){
                        res.push_back(left_index);
                        m1[s.substr(left_index, m)]++;
                        left_index += m;
                    }
                    if(m1.count(s.substr(right_index, m)) > 0 && m1[s.substr(right_index, m)] > 0){
                    //if(m1[s.substr(right_index, m)] > 0){
                        m1[s.substr(right_index, m)] -- ;
                        right_index += m;
                    }
                    else{
                        if(m1.count(s.substr(left_index, m)) > 0)
                            m1[s.substr(left_index, m)]++;
                        left_index += m;
                    }
                }
                else
                    right_index = left_index;
            }
            if((right_index - left_index) / m == n){
                res.push_back(left_index);
                m1[s.substr(left_index, m)]++;
            }
        }
        return res;
    }
};