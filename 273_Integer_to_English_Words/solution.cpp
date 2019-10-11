class Solution {
public:
    string numberToWords(int num) {
        string ret = "";
        if(num == 0) return "Zero";
        int now = 0;
        do{
            if(num % 1000 != 0){
                ret = " " + threenumberToWords(num % 1000) + add[now] + ret;
            }
            num /= 1000;
            now++;
        }while(num > 0);
        return ret.substr(1);
    }
private:
    vector<string> n1 = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
    vector<string> n2 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> add = {"", " Thousand", " Million", " Billion"};
    string threenumberToWords(int num){
        string ret;
        if(num > 99) ret = n1[num/100 - 1] + " Hundred";
        num %= 100;
        if(num == 0) return ret;
        if(num <= 20){
            if(ret == "") return n1[num-1];
            return ret + " " + n1[num-1];
        }
        else{
            if(ret == "")
                ret = n2[num/10-2];
            else ret = ret + " " + n2[num/10-2];
            num %= 10;
            if(num == 0) return ret;
            return ret + " " + n1[num-1];
        }
    }
};