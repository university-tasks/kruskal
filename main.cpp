//  clang++ -o main main.cpp

#include "./generateEdges.cpp"
#include "./generateVertices.cpp"
#include "./kruskal.cpp"

using namespace std;

int main() {
    int size;
    cout << "Enter the number of vertices: ";
    cin >> size;

    const vector<int> vertices = generateVertices(size);
    const vector<pair<int, pair<int, int> > > edges = generateEdges(vertices);
    cout << "GENERATED EDGES: \n";
    printEdges(edges);

    const vector<pair<int, pair<int, int> > > mst = kruskal(edges, vertices);

    int cost = 0;
    for (size_t i = 0; i < mst.size(); ++i) {
        cost += mst[i].first;
    }

    cout << "\nCOST: " << cost << "\n";
    cout << "MINIMUM SPANNING TREE:\n";
    printEdges(mst);

    return 0;
}