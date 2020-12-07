#include <iostream>
#include <vector>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;

   public:
    DSU(const vector<int> &vertices);
    ~DSU();
    void make(int v);
    int find(int u);
    void merge(int x, int y);
    void print();
};

DSU::DSU(const vector<int> &vertices) {
    parent = vertices;
    for (size_t i = 0; i < vertices.size(); ++i) {
        rank.push_back(0);
    }
}

DSU::~DSU() {
    parent.clear();
    rank.clear();
}

void DSU::make(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int DSU::find(int u) {
    if (u != parent[u])
        parent[u] = find(parent[u]);
    return parent[u];
}

void DSU::merge(int x, int y) {
    if ((x = find(x)) == (y = find(y)))
        return;

    if (rank[x] < rank[y])
        parent[x] = y;
    else {
        parent[y] = x;
        if (rank[x] == rank[y])
            ++rank[x];
    }
}

void DSU::print() {
    for (size_t i = 0; i < parent.size(); ++i) {
        cout << "[ " << parent[i] << ", " << rank[i] << " ]"
             << "\n";
    }
}
