#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stack>
#include <vector>
#include "singlylinkedlist.hpp"

Node* initList(int n = 0) {
    if (n == 0) return nullptr;
    srand(time(NULL));
    Node* head = new Node(rand() % 100);
    Node* node = head;
    for (int i = 1; i < n; i++) {
        node->next = new Node(rand() % 100);
        node = node->next;
    }

    return head;
}

Node* initList(std::vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* node = head;
    for (int i = 1; i < arr.size(); i++) {
        node->next = new Node(arr[i]);
        node = node->next;
    }
    return head;
}

void printList(Node* head) {
    for (Node* node = head; node != nullptr; node = node->next) {
        std::cout << node->data << " ";
    }
    printf("\n");
}

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) return true;

    Node *slow = head, *fast = head;
    std::stack<int> stk;
    while (fast != nullptr) {
        stk.push(slow->data);
        if (fast->next == nullptr) {  // Odd end
            stk.pop();
            fast = nullptr;
        } else if (fast->next->next == nullptr) {  // Even end
            fast = nullptr;
        } else {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    slow = slow->next;

    while (slow != nullptr) {
        if (slow->data != stk.top()) return false;
        stk.pop();
        slow = slow->next;
    }

    return true;
}

int main() {
    std::vector<int> arr = {0, 3};
    Node* slist = initList(arr);
    printList(slist);
    std::cout << isPalindrome(slist);
}
