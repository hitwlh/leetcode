class Solution {
public:
    string originalDigits(string s) {
        map<int, int> mymap;
        for(int i = 0; i < s.length(); i++)
            mymap[s[i]]++;
        vector<int> vec(10, 0);
        
        vec[0] = mymap['z'];
        mymap['e'] -= mymap['z'];
        mymap['r'] -= mymap['z'];
        mymap['o'] -= mymap['z'];
        mymap['z'] = 0;
        
        vec[6] = mymap['x'];
        mymap['s'] -= mymap['x'];
        mymap['i'] -= mymap['x'];
        mymap['x'] = 0;
        
        
        vec[7] = mymap['s'];
        mymap['e'] -= mymap['s'];
        mymap['e'] -= mymap['s'];
        mymap['v'] -= mymap['s'];
        mymap['n'] -= mymap['s'];
        mymap['s'] = 0;
        
        
        vec[4] = mymap['u'];
        mymap['f'] -= mymap['u'];
        mymap['o'] -= mymap['u'];
        mymap['r'] -= mymap['u'];
        mymap['u'] = 0;
        
        vec[5] = mymap['f'];
        mymap['i'] -= mymap['f'];
        mymap['v'] -= mymap['f'];
        mymap['e'] -= mymap['f'];
        mymap['f'] = 0;
        
        
        vec[8] = mymap['g'];
        mymap['e'] -= mymap['g'];
        mymap['i'] -= mymap['g'];
        mymap['h'] -= mymap['g'];
        mymap['t'] -= mymap['g'];
        mymap['g'] = 0;
        
        
        vec[3] = mymap['r'];
        mymap['t'] -= mymap['r'];
        mymap['h'] -= mymap['r'];
        mymap['e'] -= mymap['r'];
        mymap['e'] -= mymap['r'];
        mymap['r'] = 0;
        
        
        vec[9] = mymap['i'];
        mymap['e'] -= mymap['i'];
        mymap['n'] -= mymap['i'];
        mymap['n'] -= mymap['i'];
        mymap['i'] = 0;
        
        vec[2] = mymap['t'];
        mymap['w'] -= mymap['t'];
        mymap['o'] -= mymap['t'];
        mymap['t'] = 0;
        
        vec[1] = mymap['o'];
        mymap['n'] -= mymap['o'];
        mymap['e'] -= mymap['o'];
        mymap['o'] = 0;
        for(int i = 0; i < 10; i++)
            cout << i << ": " << vec[i] << endl;
        string ret;
        for(int i = 0; i < 10; i++)
            ret.append(vec[i], i+'0');
        return ret;
    }
};