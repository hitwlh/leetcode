class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
            return 0;
        map<char,int> get;
        int best = 1,try_count=1;
        get[s[0]] = 0;
        int left_index = 0;
        for(int i=1;i<s.length();i++)
        {
            if(get.find(s[i])==get.end()||get[s[i]]<left_index){
                try_count++;
                get[s[i]] = i;
            }
            else
            {
                best = best>try_count?best:try_count;
                left_index = get[s[i]]+1;
                get[s[i]] = i;
                try_count = i - left_index +1;
            }
        }
        if(try_count>best)
            best = try_count;
        return best;
    }
};