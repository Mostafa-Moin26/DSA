// Problem link ---->
https://leetcode.com/problems/lru-cache/description/

// Solution ---->
class LRUCache {
public:
    unordered_map<int, int> mp;
    unordered_map<int, list<int>::iterator> address;
    list<int> lru;
    int maxCapacity;

    void evict() {
        mp.erase(lru.front());
        address.erase(lru.front());
        lru.pop_front();
    }

    LRUCache(int capacity) {
        maxCapacity = capacity;
    }
    
    int get(int key) {
        
        if (!mp.count(key)) {
            return -1;
        }
        lru.erase(address[key]);
        lru.push_back(key);
        address[key] = --lru.end();
        return mp[key];
    }
    
    void put(int key, int value) {

        if (lru.size() == maxCapacity && !mp.count(key)) {
            evict();
        }

        if (mp.count(key)) {
          lru.erase(address[key]);
        }

        lru.push_back(key);
        address[key] = --lru.end();
        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */