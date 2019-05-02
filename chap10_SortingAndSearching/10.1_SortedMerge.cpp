// LC #88 (Vector)
// LC #21 (List)
#include <iostream>
#include <vector>
#include "printer.hpp"
#include "singlylinkedlist.hpp"

Node* mergeTwoLists(Node* l1, Node* l2) {
    Node* dummyHead = new Node();
    Node* head = dummyHead;

    while (l2 != nullptr) {
        if (l1 != nullptr && l1->data < l2->data) {
            head->next = l1;
            l1 = l1->next;
        } else {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }

    if (l1 != nullptr) head->next = l1;

    return dummyHead->next;
}

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    size_t end = m + n - 1;
    m--;
    n--;

    while (n >= 0) {
        if (m >= 0 && nums1[m] > nums2[n])
            nums1[end--] = nums1[m--];
        else
            nums1[end--] = nums2[n--];
    }
}

int main(int argc, const char* argv[]) {
    std::vector<int> nums1 = {0, 0, 3, 0, 0, 0, 0, 0, 0};
    std::vector<int> nums2 = {-1, 1, 1, 1, 2, 3};
    merge(nums1, 3, nums2, 6);
    printVec(nums1);
    return 0;
}
