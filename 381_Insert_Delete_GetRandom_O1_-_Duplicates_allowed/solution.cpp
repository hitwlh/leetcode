class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        ;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        mmp[val].insert(set.size());
        set.push_back(val);
        return mmp[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val){
        if(mmp.find(val) == mmp.end() || mmp[val].empty()) return false;
        if(set.back() == val){
            set.pop_back();
            mmp[val].erase(set.size());
        }else{
            int index = *mmp[val].begin();
            //swap(set[set.size()-1], set[index]);
            set[index] = set[set.size()-1];
            mmp[set[index]].erase(set.size()-1);
            mmp[val].erase(index);
            mmp[set[index]].insert(index);
            set.pop_back();
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return set[rand() % set.size()];
    }
private:
    unordered_map<int, unordered_set<unsigned int>> mmp;
    vector<int> set;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */