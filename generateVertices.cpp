#include <iostream>
#include <vector>

using namespace std;

vector<int> generateVertices(int n) {
    vector<int> result;
    for (size_t i = 0; i < n; ++i) {
        result.push_back(i);
    }
    return result;
}