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

Node* addLists(Node* list1, Node* list2) {
    if (list1 == nullptr && list2 == nullptr) return new Node(0);

    Node dummy;
    Node* dummyHead = &dummy;
    Node* node = dummyHead;
    int carrier = 0;

    while (list1 != nullptr || list2 != nullptr) {
        int val1 = (list1 == nullptr) ? 0 : list1->data;
        int val2 = (list2 == nullptr) ? 0 : list2->data;
        int sum = val1 + val2 + carrier;
        carrier = sum/10;
        node->next = new Node(sum - 10*carrier);

        list1 = (list1 == nullptr) ? nullptr : list1->next;
        list2 = (list2 == nullptr) ? nullptr : list2->next;
        node = node->next;
    }
    if (carrier != 0) {
        node->next = new Node(carrier);
    }

    return dummyHead->next;
}

int main()
{
    std::vector<int> arr1 = {1, 9, 9, 9, 9}, arr2 = {1, 3, 2};
    Node* list1 = initList(arr1);
    Node* list2 = initList(arr2);
    printList(list1);
    printList(list2);

    Node* sum = addLists(list1, list2);

    printList(sum);
}
