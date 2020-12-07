#include "./DSU.cpp"
#include "./printEdges.cpp"

bool comp(const pair<int, pair<int, int> > &a,
          const pair<int, pair<int, int> > &b) {
    return (a.first < b.first);
}

vector<pair<int, pair<int, int> > > kruskal(const vector<pair<int, pair<int, int> > > &edges,
                                            const vector<int> &vertices) {
    vector<pair<int, pair<int, int> > > result;

    vector<pair<int, pair<int, int> > > E = edges;
    sort(E.begin(), E.end(), comp);
    cout << "\nSORTED EDGES:\n";
    printEdges(E);

    DSU dsu(vertices);

    int weight = 0;
    for (size_t i = 0; i < E.size(); ++i) {
        int set_u = dsu.find(E[i].second.first);
        int set_v = dsu.find(E[i].second.second);

        if (set_u != set_v) {
            result.push_back(make_pair(E[i].first,
                                       make_pair(E[i].second.first, E[i].second.second)));

            dsu.merge(set_u, set_v);
        }
    }

    return result;
}
