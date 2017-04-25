class LRUCache {
public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        if(index.find(key) == index.end()) return -1;
        else{
            data.splice(data.begin(), data, index[key]);
            //index[key] = data.begin();
            return data.front().second;
        }
    }
    void put(int key, int value) {
        if(index.find(key) == index.end()){
            data.push_front({key, value});
            index[key] = data.begin();
            if(data.size() > maxSize){
                index.erase(data.back().first);
                data.pop_back();
            }
        }else{
            data.splice(data.begin(), data, index[key]);
            //index[key] = data.begin();
            data.front().second = value;
        }
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> index;
    list<pair<int, int>> data;
    int maxSize;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */