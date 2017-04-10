class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> first;
        first.assign (n,"");
        for(int i = 3; i<=n; i+=3)
            first[i-1] = "Fizz";
        for(int i = 5; i<=n; i+=5)
            first[i-1] += "Buzz";
        for(int i = 0; i<n; i++){
            if(first[i] == ""){
                stringstream ss;
                ss << (i+1);
                first[i] = ss.str();
                
            }
        }
        return first;
    }
};