#include <iostream>
#include <vector>

using namespace std;

vector<int> generateVertices(int n) {
    vector<int> result;

    cout << "GENERATED VERTICES:\n";
    for (size_t i = 0; i < n; ++i) {
        result.push_back(i);
        cout << result[i] << " ";
    }
    cout << "\n";

    return result;
}