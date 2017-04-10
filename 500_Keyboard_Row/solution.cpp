class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        map<char, int> mymap;
        mymap['q'] = 1;
        mymap['w'] = 1;
        mymap['e'] = 1;
        mymap['r'] = 1;
        mymap['t'] = 1;
        mymap['y'] = 1;
        mymap['u'] = 1;
        mymap['i'] = 1;
        mymap['o'] = 1;
        mymap['p'] = 1;
        mymap['a'] = 2;
        mymap['s'] = 2;
        mymap['d'] = 2;
        mymap['f'] = 2;
        mymap['g'] = 2;
        mymap['h'] = 2;
        mymap['j'] = 2;
        mymap['k'] = 2;
        mymap['l'] = 2;
        mymap['z'] = 3;
        mymap['x'] = 3;
        mymap['c'] = 3;
        mymap['v'] = 3;
        mymap['b'] = 3;
        mymap['n'] = 3;
        mymap['m'] = 3;
        for(int i = 0; i< words.size(); i++){
            string s = words[i];
            int type;
            bool flag = true;
            if(s.length() >= 1)
                type = (s[0] >= 'a' && s[0] <= 'z')?mymap[s[0]]:mymap[s[0] + 'a'- 'A'];
            for(int j=1; j<s.length(); j++){
                int tmp = (s[j] >= 'a' && s[j] <= 'z')?mymap[s[j]]:mymap[s[j] + 'a'- 'A'];
                if(tmp != type){
                    flag = false;
                    break;
                }
            }
            if(flag)
                res.push_back(s);
        }
        return res;
    }
};