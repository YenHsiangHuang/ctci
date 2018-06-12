#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <unordered_map>
#include "binarytree.h"

int main()
{
    int nElem = 50;
    std::vector<int> vec;
    for (int i = 0; i < nElem; i++) {
        vec.push_back(i);
    }

    BinarySearchTree tree;
    tree.createMinimalBST(vec);

    std::unordered_map<int, int> mp;

    tree.getRandomNode();
    for (int i = 0; i < 1000; i++) {
        mp[tree.getRandomNode()->data]++;
    }

    printf("  Node  |  Percentage  \n");
    for (auto &it : mp) {
        printf("%5d         %2.3f\n", it.first, it.second/1000.0);
    }
}
