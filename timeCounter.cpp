#include <chrono>
#include <vector>

#include "./kruskal.cpp"

double timeCounter(vector<int> vertices, vector<pair<int, pair<int, int> > > edges) {
    std::__1::chrono::steady_clock::rep time = 0;
    for (size_t i = 0; i < 20; ++i) {
        std::__1::chrono::steady_clock::time_point start = chrono::steady_clock::now();
        const vector<pair<int, pair<int, int> > > mst = kruskal(edges, vertices);
        std::__1::chrono::steady_clock::time_point end = chrono::steady_clock::now();
        time += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    }
    return (double(time) / 20)/ 1000000000;
}