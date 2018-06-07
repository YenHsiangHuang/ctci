// Similar to LC #257

#include <iostream>
#include <queue>
#include <unordered_set>
#include "graph.h"

using namespace std;

// Search function implemented in graph.cc

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
