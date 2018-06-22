#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <class T>
class SetOfStacks {
   public:
   public:
    void push(T item);
    void pop();
    void popAt(int idx);  // perform pop at specific stack

    T top();
    T topAt(int idx);

    bool empty();
    size_t size();

   private:
    const int MAX_STACK_SIZE = 10;
    vector<stack<T>> setOfStacks;
    void createNewStack(T item);
};

template <class T>
void SetOfStacks<T>::push(T item) {
    if (setOfStacks.empty() || setOfStacks.back().size() >= MAX_STACK_SIZE) {
        createNewStack(item);
        return;
    }

    setOfStacks.back().push(item);
}

template <class T>
void SetOfStacks<T>::pop() {
    stack<T>* lastStk = &setOfStacks.back();
    (*lastStk).pop();

    if ((*lastStk).empty()) {
        setOfStacks.pop_back();
    }
}

// Do I need to pack the stacks so that every single stack is full?
template <class T>
void SetOfStacks<T>::popAt(int idx) {
    if (idx < 0 || idx >= setOfStacks.size()) return;
    stack<T>* stk = &setOfStacks.at(idx);
    (*stk).pop();
    if ((*stk).empty()) setOfStacks.erase(setOfStacks.begin() + idx);
}

template <class T>
T SetOfStacks<T>::top() {
    return setOfStacks.back().top();
}

template <class T>
T SetOfStacks<T>::topAt(int idx) {
    return setOfStacks.at(idx).top();
}

template <class T>
bool SetOfStacks<T>::empty() {
    return setOfStacks.empty();
}

template <class T>
size_t SetOfStacks<T>::size() {
    size_t sum = 0;
    for (auto& it : setOfStacks) {
        sum += it.size();
    }
    return sum;
}

template <class T>
void SetOfStacks<T>::createNewStack(T item) {
    stack<T> stk;
    stk.push(item);
    setOfStacks.push_back(stk);
}

SetOfStacks<int> initStack() {
    srand(time(nullptr));
    SetOfStacks<int> stk;
    for (int i = 0; i < 20; i++) {
        stk.push(i);
    }
    return stk;
}

void printStack(SetOfStacks<int> stk) {
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    SetOfStacks<int> stk = initStack();
    cout << stk.topAt(0) << endl;
    stk.popAt(0);
    cout << stk.topAt(0);

    return 0;
}
