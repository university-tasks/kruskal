#include <algorithm>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int> > > generateEdges(const vector<int> &vertices) {
    srand((unsigned)time(0));

    set<pair<int, pair<int, int> > > edges_set;

    for (int i = 0; i < vertices.size(); ++i) {
        for (int j = rand() % vertices.size(); j < vertices.size(); ++j) {
            if (j == i or j == i - 1) continue;

            const int vertex1 = vertices[i];
            const int vertex2 = vertices[rand() % vertices.size()];

            if (vertex1 != vertex2)
                edges_set.insert(make_pair(0,
                                           make_pair(min(vertex1, vertex2), max(vertex1, vertex2))));
        }
    }

    vector<pair<int, pair<int, int> > > result(edges_set.begin(), edges_set.end());
    for (size_t i = 0; i < result.size(); ++i) result[i].first = rand() % 50 + 1;
    edges_set.clear();

    return result;
}