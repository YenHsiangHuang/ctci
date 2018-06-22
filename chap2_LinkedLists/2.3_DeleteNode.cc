#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "singlylinkedlist.h"

Node* initList(int n) {
    srand(time(NULL));
    Node* head = new Node(rand() % 5);
    Node* node = head;
    for (int i = 1; i < n; i++) {
        node->next = new Node(rand() % 5);
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

int main() {
    // std::vector<int> arr = {0, 4, 4, 1, 0, 4, 2, 0, 3, 4};
    Node* head = initList(10);
    printList(head);

    int k = 4;
    Node* node = head;
    for (int i = 0; i < k; i++) {
        node = node->next;
    }
    node->deleteNode(node);

    printList(head);
}
