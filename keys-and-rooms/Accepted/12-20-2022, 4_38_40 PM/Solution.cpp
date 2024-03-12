// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<vector<int>> q; q.push(rooms[0]);
        bitset<1001> b; b.set(0);
        while(!q.empty()){    
            vector<int> top = q.front(); q.pop();
            for(int i: top){
                if(!b[i]) q.push(rooms[i]);
                b[i] = 1;
            }
        }
        return b.count() == rooms.size();
    }
};