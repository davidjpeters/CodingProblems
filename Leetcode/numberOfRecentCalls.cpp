#include <queue>

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        
        while (q.front() < q.back() - 3000) {
            q.pop();
        }
        return q.size();
    }

private:
    std::queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */