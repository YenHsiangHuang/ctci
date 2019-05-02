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


int main()
{
    //std::vector<int> arr = {0, 4, 4, 1, 0, 4, 2, 0, 3, 4};
    //Node* head = initList(arr);
    Node* head = initList();

    printList(head);
    head = head->remove(head, 2);
    printList(head);
    //head->removeDup(head);
    head->removeDupInPlace(head);
    printList(head);

    return 0;
}
