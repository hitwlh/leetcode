class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mymap1, mymap2;
        for(auto i: t) mymap1[i]++;
        int left = 0, right = 0, found = 0, MIN = INT_MAX;
        string ret;
        while(right < s.length()){
            if(mymap1.find(s[right]) != mymap1.end() && mymap1[s[right]] > 0){
                mymap2[s[right]]++;
                if(mymap2[s[right]] <= mymap1[s[right]]) found++;
            }
            if(found >= t.length()){
                //cout << left << endl;
                while(mymap1.find(s[left]) == mymap1.end() || mymap1[s[left]] < mymap2[s[left]]){
                    if(mymap1.find(s[left]) != mymap1.end()) mymap2[s[left]]--;
                    left++;
                }
                //cout << right << " " << left << endl;
                if(right - left + 1 < MIN){
                    MIN = right - left + 1;
                    ret = s.substr(left, MIN);
                }
            }
            right ++;
        }
        return ret;
    }
};