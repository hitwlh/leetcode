class Solution{
public:
    string validIPAddress(string IP) {
        cout << IP << endl;
        for(int i = 0; i < IP.length(); i++){
            if(IP[i] == '.') return IPV4(IP);
            if(IP[i] == ':') return IPV6(IP);
        }
        return "Neither";
    }
private:
    string IPV4(string IP){
        string use;
        int count = 0;
        for(int i = 0; i < IP.length(); i++){
            if(IP[i] == '.'){
                if(++count > 3) return "Neither";
                if(use.size() < 1 || (use[0] == '0' && use.size() > 1) || use.size() > 3 || atoi(use.c_str()) > 255) return "Neither";
                use = "";
            }else{
                if(!(isdigit(IP[i]))) return "Neither";
                use += IP[i];
            }
        }
        if(count != 3 || use.size() < 1 || (use[0] == '0' && use.size() > 1) || use.size() > 3 || atoi(use.c_str()) > 255) return "Neither";
        return "IPv4";
    }
    string IPV6(string IP){
        string use;
        int count = 0;
        for(int i = 0; i < IP.length(); i++){
            if(IP[i] == ':'){
                if(++count > 7) return "Neither";
                if(use.size() < 1 || use.size() > 4 ) return "Neither";
                use = "";
            }else{
                if(!isdigit(IP[i]) && (IP[i] < 65 || IP[i] > 70) && (IP[i] < 97 || IP[i] > 102)) return "Neither";
                use += IP[i];
            }
        }
        if(count != 7 || use.size() < 1 || use.size() > 4 ) return "Neither";
        return "IPv6";
    }
};