//  Least Frequently Used (LFU)
// 插入元素时, 若容量已经满了, 淘汰最低频的元素
class LFUCache {
public:
    LFUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (kv.count(key) == 0) {
            return -1;
        }
        updateLFU(key);
        return kv[key].first;
    }

    void put(int key, int value) {
        if (size <= 0) {
            return;
        }
        // 如果size没满， 继续插入, 如果满了并且是全新的key, 删除最低频率的元素
        // 多个相同频率的删除长时间未使用的
        if (kv.size() == size && kv.count(key) == 0) {
            evict();
        }
        updateLFU(key);
        kv[key].first = value;
    }

    void updateLFU(int key) {
        // 如果是已经存在的key
        if (kv.count(key) != 0) {
            lfu[kv[key].second].erase(mpIter[key]);
        }
        else {
            minFreq = 1; // 插入全新元素的时候, minFreq置为1
        }
        // kv[key]: {value, freq}
        // lfu: {freq: list<int>}, lfu中靠前的元素是最近调用的元素, 靠后的是很久没使用过得元素
        // 插入一个新的key时, ++kv[key].second就是1, kv[key].first就是0
        ++kv[key].second;
        lfu[kv[key].second].push_front(key);
        mpIter[key] = lfu[kv[key].second].begin();

        if (lfu[minFreq].size() == 0) {
            ++minFreq;
        }
    }

    void evict() {
        // lfu中靠前的是最近调用的, 靠后的是最近没使用过的
        kv.erase(lfu[minFreq].back());
        mpIter.erase(lfu[minFreq].back());
        lfu[minFreq].pop_back();
    }

private:
    int size = 0;
    int minFreq = 0;
    unordered_map<int, pair<int, int>> kv;            // key -> {value, freq};
    unordered_map<int, list<int>::iterator> mpIter;   // key -> iterator
    unordered_map<int, list<int> > lfu;               // freq -> key list
};
