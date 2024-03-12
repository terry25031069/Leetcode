// https://leetcode.com/problems/design-twitter

class Twitter {
public:
    using pii = pair<int, int>;
    vector<pii> v;
    vector<set<int>> follower;

    Twitter() {
        v.clear();
        follower.resize(501);
        for(int i = 0; i < 501; i++){
            follower[i].clear();
            follower[i].insert(i);
        }
    }
    
    void postTweet(int userId, int tweetId) {
        v.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(pii p: v){
            if(follower[userId].find(p.first) != follower[userId].end()){
                ans.push_back(p.second);
            }
        }
        reverse(ans.begin(), ans.end());
        if(ans.size() <= 10) return ans;
        vector<int>anss(ans.begin(), ans.begin() + 10);
        return anss;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */