#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void printEdges(vector<pair<int, pair<int, int> > > graph) {
    for (int i = 0; i < graph.size(); ++i) {
        cout << "{ " << setw(2) << left << graph[i].first << ", "
             << "< " << graph[i].second.first << "," << graph[i].second.second << " >"
             << " }\n";
    }
}
