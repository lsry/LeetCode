package L300;

import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class LeetCode0355 {
}

class Twitter {
    private static int versionId = 0;
   
    class TWNode {
        public int id;
        public long version;
        
        public TWNode(int id) {
            this.id = id;
            this.version = versionId;
            ++versionId;
        }
    }

    Map<Integer,Set<Integer>> users;
    Map<Integer,LinkedList<TWNode>> twitters;

    /** Initialize your data structure here. */
    public Twitter() {
        users = new HashMap<>();
        twitters = new HashMap<>();
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        if (users.get(userId) == null) {
            users.put(userId, new HashSet<>());
        }
        LinkedList<TWNode> userTwitters = twitters.get(userId);
        if (userTwitters == null) {
            userTwitters = new LinkedList<>();
        }
        userTwitters.addFirst(new TWNode(tweetId));
        twitters.put(userId, userTwitters);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        if (users.get(userId) == null) {
            users.put(userId, new HashSet<>());
        }
        LinkedList<TWNode> ts = new LinkedList<>();
        int index = 0;
        LinkedList<TWNode> curTwitter = twitters.get(userId);
        if (curTwitter != null && !curTwitter.isEmpty()) {
            for (TWNode t : curTwitter) {
                if (index >= 11) {
                    break;
                }
                ts.offer(t);
                ++index;
            }
        }
        Set<Integer> si = users.get(userId);
        if (si != null && !si.isEmpty()) {
            for (Integer i : si) {
                curTwitter = twitters.get(i);
                if (curTwitter != null && !curTwitter.isEmpty()) {
                    index = 0;
                    for (TWNode t : curTwitter) {
                        if (index >= 11) {
                            break;
                        }
                        ts.offer(t);
                        ++index;
                    }
                }
            }
        }
        Collections.sort(ts, (a,b) -> {
            return a.version < b.version ? 1 : -1;
        });
        List<Integer> res = new LinkedList<>();
        index = 0;
        for (TWNode i : ts) {
            if (index >= 10) {
                break;
            }
            res.add(i.id);
            ++index;
        }
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if (followeeId == followerId) {
            return;
        }
        Set<Integer> ufollowers = users.get(followerId);
        if (users.get(followerId) == null) {
            ufollowers = new HashSet<>();
            users.put(followerId, ufollowers);
        }
        ufollowers.add(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        if (followeeId == followerId) {
            return;
        }
        Set<Integer> ufollowers = users.get(followerId);
        if (ufollowers != null) {
            ufollowers.remove(followeeId);
        } else {
            ufollowers = new HashSet<>();
            users.put(followerId, ufollowers);
        }
    }
}