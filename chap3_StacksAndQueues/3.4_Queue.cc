#include <stack>

using namespace std;

template <class T>
class Queue
{
public:
    void push(T item);
    void pop();
    T front();
    bool empty();
    size_t size();
private:
    stack<T> stk, stkRev;
    inline void shiftStack();
};

template <class T>
void Queue<T>::push(T item) {
    stk.push(item);
}

template <class T>
void Queue<T>::pop() {
    shiftStack();
    stkRev.pop();
}

template <class T>
T Queue<T>::front() {
    shiftStack();
    return stkRev.top();
}

template <class T>
bool Queue<T>::empty() {
    return stk.empty() && stkRev.empty();
}

template <class T>
size_t Queue<T>::size() {
    return stk.size() + stkRev.size();
}

template <class T>
inline void Queue<T>::shiftStack() {
    if (!stkRev.empty()) return;

    while (!stk.empty()) {
        stkRev.push(stk.top());
        stk.pop();
    }
}


int main()
{
    Queue<int> q;
    for (int i = 0; i < 10; i++) {
        q.push(i);
    }

    for (int i = 0; i < 10; i++) {
        printf("%d \n", q.front());
        q.pop();
    }
    return 0;
}
