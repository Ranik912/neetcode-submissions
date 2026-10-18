class LRUCache {
public:
    list<int>dll;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }

    void mostRescentlyUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        mostRescentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mostRescentlyUsed(key);
            mp[key].second = value;
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }
        if(n < 0){
            int toDel = dll.back();
            mp.erase(toDel);
            dll.pop_back();
            n++;
        }
    }
};
