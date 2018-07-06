// LC #295
// Find median from stream
#include <iostream>
#include <queue>


// Elegant solution on LC
class MedianFinderLC {
   public:
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        return (small.size() == large.size())
                   ? (small.top() + large.top()) / 2.0
                   : small.top();
    }

   private:
    std::priority_queue<int> small;
    std::priority_queue<int, std::vector<int>, std::greater<int>> large;
};

// My implementation
class MedianFinder {
   public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        smallQ.emplace(num);

        if (smallQ.size() - largeQ.size() > 1) {
            largeQ.push(smallQ.top());
            smallQ.pop();
        }

        if (!largeQ.empty() && smallQ.top() > largeQ.top()) {
            largeQ.push(smallQ.top());
            smallQ.pop();
            smallQ.push(largeQ.top());
            largeQ.pop();
        }
    }

    double findMedian() {
        return (smallQ.size() == largeQ.size())
                   ? (smallQ.top() + largeQ.top()) / 2.0
                   : smallQ.top();
    }

   private:
    std::priority_queue<int>
        smallQ;  // Largest on top
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        largeQ;  // Smallest on top
};

int main(int argc, const char *argv[])
{
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    std::cout << mf.findMedian() << std::endl;
    mf.addNum(3);
    std::cout << mf.findMedian() << std::endl;

    MedianFinderLC mflc;
    mflc.addNum(1);
    mflc.addNum(2);
    std::cout << mflc.findMedian() << std::endl;
    mflc.addNum(3);
    std::cout << mflc.findMedian() << std::endl;
    return 0;
}
