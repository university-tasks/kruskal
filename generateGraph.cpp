#include <algorithm>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>

#include "./generateVertices.cpp"
#include "./printGraph.cpp"

vector<pair<int, pair<int, int> > > generateConnectedRandomGraph(int n) {
    srand((unsigned)time(0));

    vector<int> weights;
    set<pair<int, pair<int, int> > > edges;
    const vector<int> vertices = generateVertices(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < rand() % n; ++j) {
            if (j == i or j == i - 1) continue;

            const int vertex1 = vertices[i];
            const int vertex2 = vertices[rand() % n];

            if (vertex1 != vertex2)
                edges.insert(make_pair(rand() % 50 + 1,
                                       make_pair(min(vertex1, vertex2), max(vertex1, vertex2))));
        }
    }

    vector<pair<int, pair<int, int> > > graph(edges.begin(), edges.end());
    cout << "The generated random graph is: \n";
    printGraph(graph);
    return graph;
}