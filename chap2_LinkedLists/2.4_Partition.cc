#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "singlylinkedlist.h"

Node* initList(int n) {
    if (n == 0) return nullptr;
    srand(time(NULL));
    Node* head = new Node(rand()%100);
    Node* node = head;
    for (int i = 1; i < n; i++) {
        node->next = new Node(rand()%100);
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

int main()
{
    //std::vector<int> arr = {1, 4, 4, 1, 1, 4, 2, 1, 3, 4};
    Node* head = initList(20);
    printList(head);

    head = head->partition(head, 50);

    printList(head);
}
