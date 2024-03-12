// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream

class DataStream {
public:
    int kk, cd;
    DataStream(int value, int k) {
        vector<int>arr;
        kk = k;
        cd = 0;
    }
    
    bool consec(int num) {
        if(num == kk){
            if(cd == 0)return true;
            cd--;
        }
        cd = kk; return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */