class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int cache;
    int need_cache;
    PeekingIterator(const vector<int>& nums) : Iterator(nums), need_cache(true) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if(!hasNext())
            return -1;
        if(need_cache){
            cache = next();
            need_cache = false;
        }
        return cache;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if(need_cache == false){
            need_cache = true;
            return cache;
        }
        else{
            return Iterator::next();
        }
    }

    bool hasNext() const {
        if(!need_cache)
            return true;
        return Iterator::hasNext();
    }
};