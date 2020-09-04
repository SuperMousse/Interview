// LRU: Least Recently Used, 最近最少使用, 常用的页面管理算法, 选择最近最久未使用的页面进行淘汰
// 插入元素时, 若容量已经满了, 淘汰最久没有使用过的元素

class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (kv.count(key) == 0) {
            return -1;
        }
        updateLRU(key);
        return kv[key];
    }

    void put(int key, int value) {
        // 如果size没满， 继续插入， 如果满了并且是全新的key, 删除最久没使用过得key
        if (kv.size() == size && kv.count(key) == 0) {
            evict();
        }
        updateLRU(key);
        kv[key] = value;
    }

    void updateLRU(int key) {
        // 如果是已经存在的key
        if (kv.count(key) != 0) {
            lru.erase(mp[key]);
        }
        // lru中靠前的元素是最近调用的元素, 靠后的是很久没使用过得元素
        lru.push_front(key);
        mp[key] = lru.begin();
    }

    void evict() {
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }

private:
    int size = 0;
    list<int> lru;                              // MRU ... LRU
    unordered_map<int, list<int>::iterator> mp; // key -> iterator
    unordered_map<int, int> kv;                 // key -> value
};
