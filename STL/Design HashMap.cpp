// Problem link ---->
https://leetcode.com/problems/design-hashmap/description/

// Solution ---->
class MyHashMap {
public:
    
    int data[1000001];

    MyHashMap() {
        fill(data, data + 1000001, -1);
    }
    
    void put(int key, int value) {
        data[key] = value;
    }
    
    int get(int key) {
        return data[key];
    }
    
    void remove(int key) {
        data[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

// Hasing Solution --->
class MyHashMap {
public:
    
    static const int bucket_size = 10004;
    static const int base = 991;
    vector<pair<int, int>> keyValueMap[bucket_size];

    int getHash(int key) {
        return (key * base) % bucket_size;
    }

    bool isKeyExist(int key, int value) {
        int hashValue = getHash(key);

        for (auto & keyValuePair : keyValueMap[hashValue]) {
            if (keyValuePair.first == key) {
                keyValuePair.second = value;
                
                return true;
            }
        }

        return false;
    }

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int hashValue = getHash(key);

        if (!isKeyExist(key, value)) {
            keyValueMap[hashValue].push_back({key, value});
        }
    }
    
    int get(int key) {
        int hashValue = getHash(key);

        for (auto& keyValuePair : keyValueMap[hashValue]) {
            if (keyValuePair.first == key) {
                return keyValuePair.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int hashValue = getHash(key);

        for (auto& keyValuePair : keyValueMap[hashValue]) {
            if (keyValuePair.first == key) {
                swap(keyValuePair, keyValueMap[hashValue].back());
                keyValueMap[hashValue].pop_back();
                break;
                
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */