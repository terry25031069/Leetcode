// https://leetcode.com/problems/frequency-tracker

class FrequencyTracker {
public:
    int f[100001] = {}, ff[100001] = {};
    FrequencyTracker() {
        ff[0] = 100001;
    }
    
    void add(int number) {
        ff[f[number]]--;
        f[number] += 1;
        ff[f[number]]++;
    }
    
    void deleteOne(int number) {
        if(f[number]){
            ff[f[number]]--;
            f[number] -= 1;
            ff[f[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return ff[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */