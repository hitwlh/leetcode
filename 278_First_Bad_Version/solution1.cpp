// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 1, right = n;
        long long middle = (left + right) / 2;
        while(true){
            if(isBadVersion(left)) return left;
            while(!isBadVersion(middle)){
                if(isBadVersion(middle+1)) return middle+1;
                left = middle;
                middle = (left + right) / 2 + 1;    
            }
            right = middle;
            if(!isBadVersion(right-1)) return right;
            middle = (left + right) / 2 + 1; 
        }
    }
};