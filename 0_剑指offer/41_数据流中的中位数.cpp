// 两个堆来做，一个大根堆，一个小根堆
// 大根堆中存较小的那一半
// 小根堆中存较大的那一半
// 大根堆[1,2,3,4]，4是堆顶
// 小根堆[6,7,8,9]，6是堆顶

class MedianFinder {
   public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (a.size() != b.size()) {
            a.push(num);
            b.push(a.top());
            a.pop();
        } else {
            b.push(num);
            a.push(b.top());
            b.pop();
        }
    }

    double findMedian() {
        return a.size() != b.size() ? a.top() : (double)(a.top() + b.top()) / 2;
    }
    priority_queue<int, vector<int>, greater<int>> a;
    priority_queue<int, vector<int>, less<int>> b;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */