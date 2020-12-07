#include <ctime>
#include <random>
#include <set>
#include <vector>

using namespace std;

vector<int> generateVertices(int n) {
    srand((unsigned)time(0));

    set<int> vertices;
    while (vertices.size() < n) vertices.insert(rand() % 100);

    vector<int> result(vertices.begin(), vertices.end());
    vertices.clear();
    return result;
}