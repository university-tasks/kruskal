//  clang++ -o main main.cpp

#include "./generateEdges.cpp"
#include "./generateVertices.cpp"
#include "./timeCounter.cpp"
#include "./inputValidators.cpp"

using namespace std;


int main() {
    int n = nValidator();
    const vector<int> vertices = generateVertices(n);
    const vector<pair<int, pair<int, int> > > edges = generateEdges(vertices);

    bool needToPrintEdges = YesNotValidator("Should I print the edges?");
    if (needToPrintEdges) {
        cout << "GENERATED EDGES: \n";
        printEdges(edges);
    }

    bool isTimeCounter = YesNotValidator("Do you need to calculate the time of execution?");
    if (isTimeCounter) {
        cout << "\nTIME SPENT: " << timeCounter(vertices, edges) << " seconds\n";
        cout << "(average time after 20 runs)\n";
    }

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