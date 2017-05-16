class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> mymap1;
        map<string, char> mymap2;
        vector<string> vec;
        str =  str + " ";
        while(str.length() > 1){
            int found = str.find(" ");
            string substr = str.substr(0, found);
            //cout << substr << endl;
            str.erase(0, found + 1);
            vec.push_back(substr);
        }
        if(pattern.length() != vec.size()) return false;
        for(int i = 0; i < pattern.length(); i++){
            if(mymap1.find(pattern[i]) == mymap1.end()){
                if(mymap2.find(vec[i]) == mymap2.end()){
                    mymap1[pattern[i]] = vec[i];
                    mymap2[vec[i]] = pattern[i];
                }
                else return false;
            }else{
                if(mymap2.find(vec[i]) == mymap2.end()) return false;
                if(mymap2[vec[i]] != pattern[i] || mymap1[pattern[i]] != vec[i]) return false;
            }
        }
        return true;
    }
};