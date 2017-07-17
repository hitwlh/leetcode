class Solution {
public:
    string originalDigits(string s) {
        vector<int> vec(10, 0);
        vector<int> sc(256, 0);
        for(int i = 0; i < s.length(); i++) 
            sc[s[i]]++;
        vec[0] = sc['z'];
        vec[2] = sc['w'];
        vec[4] = sc['u'];
        vec[6] = sc['x'];
        vec[8] = sc['g'];
        
        
        vec[3] = sc['h'] - vec[8];
        vec[5] = sc['f'] - vec[4];
        vec[7] = sc['s'] - vec[6];
        vec[9] = sc['i'] - vec[8] - vec[6] - vec[5];
        vec[1] = sc['o'] - vec[0] - vec[2] - vec[4];
        
        string ret;
        for(int i = 0; i < 10; i++)
            ret.append(vec[i], i+'0');
        return ret;
    }
};