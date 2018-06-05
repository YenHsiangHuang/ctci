#include <iostream>
#include <queue>
#include <unordered_set>
#include "graph.h"

using namespace std;

// Overload the "Graph::search" function
bool Graph::search(string a, string b) {
    // Breath-first search from a to b
    Node* A = getNode(a);
    Node* B = getNode(b);

    queue<Node*> toVisit;
    unordered_set<Node*> visited;
    toVisit.push(A);

    while (!toVisit.empty()) {
        Node* curr = toVisit.front();
        toVisit.pop();
        if (curr == B) return true;

        if (visited.count(curr) == 0) {
            visited.insert(curr);
            for (auto &it : curr->children) {
                toVisit.push(it);
            }
        }
    }

    return false;
}

int main()
{
    Graph graph;
    graph.addNode("0");
    graph.addNode("1");
    graph.addNode("2");
    graph.addNode("3");
    graph.addNode("4");
    graph.addNode("5");

    graph.addChildren("0", "1");
    graph.addChildren("0", "4");
    graph.addChildren("0", "5");
    graph.addChildren("1", "3");
    graph.addChildren("1", "4");
    graph.addChildren("2", "1");
    graph.addChildren("3", "2");
    graph.addChildren("3", "4");

    string start = "0", end = "2";
    if (graph.search(start, end))
        cout << "There is a route from " << start << " to " << end << endl;
}
