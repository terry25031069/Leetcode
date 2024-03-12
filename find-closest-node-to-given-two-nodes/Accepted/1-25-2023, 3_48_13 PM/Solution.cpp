// https://leetcode.com/problems/find-closest-node-to-given-two-nodes

class Solution {
public:
    int N = 1000000000;
    vector<int> da, db;
    void dfs(int node, vector<int> &arr, vector<int> &edge){
        arr[node] = 0;
        while(edge[node] != -1 && arr[edge[node]] == N){
            arr[edge[node]] = arr[node] + 1;
            node = edge[node];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        da.resize(edges.size(), N);
        db.resize(edges.size(), N);
        dfs(node2, db, edges), dfs(node1, da, edges);
        int mi = N, ans = -1; 
        for(int i = 0; i < da.size(); i++){
            if(mi > max(da[i], db[i])){
                mi = max(da[i], db[i]);
                ans = i;
            }
        }
        if(mi == N) return -1;
        return ans;
    }
};