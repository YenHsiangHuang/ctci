#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "singlylinkedlist.hpp"

Node* initList() {
    srand(time(NULL));
    Node* head = new Node();
    Node* node = head;
    for (int i = 0; i < 9; i++) {
        node->next = new Node(rand()%5);
        node = node->next;
    }

    return head;
}

Node* initList(std::vector<int>& arr) {
    Node* head = new Node();
    Node* node = head;
    for (int i = 0; i < arr.size(); i++) {
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

// k = 0, return last itself
// k > size of list, return full list
Node* findKthToLast (Node* head, int k) {
    if (head == nullptr) return head;

    Node *nd1 = head, *nd2 = head;
    while (k != 0) {
        nd2 = nd2->next;
        if (nd2 == nullptr) return head;
        k--;
    }

    while (nd2->next != nullptr) {
        nd1 = nd1->next;
        nd2 = nd2->next;
    }
    return nd1;
}

int main()
{
    std::vector<int> arr = {0, 4, 4, 1, 0, 4, 2, 0, 3, 4};
    Node* head = initList(arr);
    printList(head);

    head = findKthToLast(head, 20);
    printList(head);
}
