class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, left = 0, val1, val2;
        while(i < version1.length() && j < version2.length()){
            left = i;
            i = findnext(version1, i);
            val1 = atoi(version1.substr(left, i - left).c_str());
            left = j;
            j = findnext(version2, j);
            val2 = atoi(version2.substr(left, j - left).c_str());
            if(val1 != val2) return val1 > val2 ? 1 : -1;
            i++, j++;
        }
        while(j < version2.length()){
            if(version2[j] != '.' && version2[j] > '0')
                return -1;
            j++;
        }
        while(i < version1.length()){
            if(version1[i] != '.' && version1[i] > '0')
                return 1;
            i++;
        }
        return 0;
    }
private:
    int findnext(string &s, int start_index){
        int i;
        for(i = start_index; i < s.length(); i++)
            if(s[i] == '.') return i;
        return i;
    }
};