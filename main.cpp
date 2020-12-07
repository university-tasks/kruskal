//  clang++ -o Kruskal Kruskal.cpp
#include <iostream>
#include <vector>

#include "./generateGraph.cpp"

using namespace std;

int main() {
    int size;
    cin >> size;
    vector<pair<int, pair<int, int> > > g = generateConnectedRandomGraph(size);

    return 0;
}