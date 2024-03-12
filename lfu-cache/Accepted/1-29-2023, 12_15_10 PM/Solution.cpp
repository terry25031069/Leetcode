// https://leetcode.com/problems/lfu-cache

class LFUCache {
public:
    unordered_map<int, list<int>> freq_list;
    unordered_map<int, tuple<int, int, list<int>::iterator>> cache;
    int min_freq;
    int cache_cap;
    
    LFUCache(int capacity) {
        cache_cap = capacity;
    }
    
    void update_freq(int key) {
        int& freq = std::get<1>(cache[key]);
        list<int>::iterator& itr = std::get<2>(cache[key]);
        
        freq_list[freq].erase(itr);
        if (freq_list[freq].empty() && min_freq == freq)
            min_freq++;
        
        freq = freq + 1;
        itr = freq_list[freq].insert(freq_list[freq].begin(), key);
    }
    
    int get(int key) {
        if (cache.count(key) == 0)
            return -1;
        
        update_freq(key);
        
        return std::get<0>(cache[key]);
    }
    
    void put(int key, int value) {
        if (cache_cap <= 0)
            return;
        
        if (cache.count(key)) {
            update_freq(key);
            std::get<0>(cache[key]) = value;
            return;
        }
        
        if (cache.size() == cache_cap) {
            cache.erase(freq_list[min_freq].back());
            freq_list[min_freq].pop_back();
        }
    
        min_freq = 1;
        freq_list[min_freq].push_front(key);
        cache[key] = make_tuple( value, min_freq, freq_list[min_freq].begin() ); 
    }
};