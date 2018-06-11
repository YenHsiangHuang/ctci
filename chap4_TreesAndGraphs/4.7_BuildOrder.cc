// Similar to LC #332 Reconstruct Itinerary

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <assert.h>
#include "graph.h"

using namespace std;

UGraph* BuildGraph(vector<string>& projects, vector<pair<string, string>>& dependencies) {
    UGraph* graph = new UGraph;
    for (auto &it : projects) {
        graph->addNode(it);
    }
    for (auto &it : dependencies) {
        graph->addEdge(it.first, it.second);
    }
    return graph;
}

vector<string> findBuildOrder(vector<string>& projects, vector<pair<string, string>>& dependencies) {
    UGraph* graph = BuildGraph(projects, dependencies);
    vector<string> res;
    while (!(graph->roots.empty())) {
        for (auto &it : graph->roots) {
            res.push_back(it->name);
        }
        graph->eraseRoots();
    }

    assert(!res.empty());
    return res;
}

void test(vector<string>& projects, vector<pair<string, string>>& dependencies) {
    auto res = findBuildOrder(projects, dependencies);
    for (auto &it : res) {
        cout << it << " " ;
    }
    cout << endl;
}


int main()
{
    vector<string> projects = {"a", "b", "c", "d", "e", "f"};
    vector<pair<string, string>> dependencies = {{"a","d"}, {"f","b"}, {"b","d"}, {"f","a"}, {"d","c"}};

    test(projects, dependencies);
}
