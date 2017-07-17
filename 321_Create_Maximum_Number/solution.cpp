class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> ret(k, -1);
        for(int lcount = max(0, k-n); lcount <= min(m, k); lcount++){
            stack<int> s1, s2;
            for(int i = 0; i < m; i++){
                while(!s1.empty() && m - i + s1.size() > lcount && s1.top() < nums1[i]) s1.pop();
                if(s1.size() < lcount) s1.push(nums1[i]);
            }
            for(int i = 0; i < n; i++){
                while(!s2.empty() && (n - i + s2.size() > k - lcount) && s2.top() < nums2[i]) s2.pop();
                if(s2.size() < k - lcount) s2.push(nums2[i]);
            }
            int ls1 = s1.size(), ls2 = s2.size();
            vector<int> v1(ls1, 0), v2(ls2, 0), MAX(ls1 + ls2, 0);
            while(!s1.empty()){
                v1[--ls1] = s1.top();
                s1.pop();
            }
            while(!s2.empty()){
                v2[--ls2] = s2.top();
                s2.pop();
            }
            int i = 0, j = 0, l = 0;
            while(l < k){
                if(i >= v1.size()) MAX[l++] = v2[j++];
                else if(j >= v2.size()) MAX[l++] = v1[i++];
                else{
                    if(v1[i] > v2[j]) MAX[l++] = v1[i++];
                    else if(v1[i] < v2[j]) MAX[l++] = v2[j++];
                    else{
                        int tmpi = i+1, tmpj = j+1, flag = 0;
                        while(tmpi < v1.size() && tmpj < v2.size()){
                            if(v1[tmpi] > v2[tmpj]){
                                MAX[l++] = v1[i++];
                                flag = 1;
                                break;
                            }else if(v1[tmpi] < v2[tmpj]){
                                MAX[l++] = v2[j++];
                                flag = 1;
                                break;
                            }else{
                                tmpi++, tmpj++;
                            }
                        }
                        if(!flag){
                            if(tmpi >= v1.size()) MAX[l++] = v2[j++];
                            else MAX[l++] = v1[i++];
                        }
                    }
                }
            }
            ret = max(ret, MAX);
        }
        return ret;
    }
};