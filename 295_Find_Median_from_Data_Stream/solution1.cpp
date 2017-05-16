class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        ;
    }
    
    void addNum(int num) {
        int left = 0, right = use.size()-1;
        //cout << "right " << right << endl;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(use[mid] < num) left = mid+1;
            else right = mid-1;
        }
        use.insert(use.begin() + left, num);
    }
    
    double findMedian() {
        //for(auto i: use) cout << i <<" ";
        //cout << endl;
        if(use.size() == 0) return -1;
        double a = 0;
        if(use.size() % 2 == 0){
            a = use[use.size()/2-1] + use[use.size()/2];
            a /= 2;
        }else
            a = use[use.size()/2];
        return a;
    }
private:
    vector<int> use;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */