#include <stdlib.h>
#include <time.h>
#include <stack>
#include <climits>

using namespace std;

void sortStack(stack<int>& stk) {
    stack<int> orderedStk;
    while (!stk.empty()) {
        int val = stk.top();
        stk.pop();
        while (!orderedStk.empty() && val > orderedStk.top()) {
            stk.push(orderedStk.top());
            orderedStk.pop();
        }
        orderedStk.push(val);
    }

    stk = orderedStk;
}

int main()
{
    srand(time(nullptr));
    stack<int> stk;
    for (int i = 0; i < 100; i++) {
        stk.push(rand()%20);
        printf("%d ", stk.top());
    }
    printf("\n");

    sortStack(stk);

    while (!stk.empty()) {
        printf("%d ", stk.top());
        stk.pop();
    }
    printf("\n");
}

