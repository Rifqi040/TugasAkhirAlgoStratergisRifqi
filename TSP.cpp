#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int V = 7; // A,B,C,D,E,F,G

int main() {
    cout << "========================\n";
    cout << "Muhammad Rifqi Aminulloh\n";
    cout << "23533806\n";
    cout << "4A\n";
    cout << "TSP\n";
    cout << "========================\n\n";

    // Input bobot
    int a,b,c,d,e,f,g,h;
    cout << "Masukkan bobot sisi berikut:\n";
    cout << "a (A–D): "; cin >> a;
    cout << "b (A–B): "; cin >> b;
    cout << "c (B–C): "; cin >> c;
    cout << "d (C–D): "; cin >> d;
    cout << "e (D–E): "; cin >> e;
    cout << "f (C–F): "; cin >> f;
    cout << "g (F–G): "; cin >> g;
    cout << "h (E–G): "; cin >> h;
    cout << endl;

    // bangun graf
    vector<pair<int,int>> adj[V];
    auto addEdge = [&](int u, int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    };
    addEdge(0,3,a); // A–D
    addEdge(0,1,b); // A–B
    addEdge(1,2,c); // B–C
    addEdge(2,3,d); // C–D
    addEdge(3,4,e); // D–E
    addEdge(2,5,f); // C–F
    addEdge(5,6,g); // F–G
    addEdge(4,6,h); // E–G

    // Dijkstra dari A(0) ke G(6)
    vector<int> dist(V, INT_MAX), parent(V, -1);
    dist[0] = 0;
    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
    pq.push({0,0});

    while (!pq.empty()) {
        auto [d_u,u] = pq.top(); pq.pop();
        if (d_u > dist[u]) continue;
        for (auto [v,w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // rekonstruksi path
    vector<int> path;
    for (int v = 6; v != -1; v = parent[v])
        path.push_back(v);

    cout << "Shortest distance A -> G = " << dist[6] << "\n";
    cout << "Path: ";
    for (int i = path.size()-1; i >= 0; --i) {
        cout << char('A' + path[i])
             << (i ? " -> " : "\n");
    }

    // helper
    auto onPath = [&](int u,int v){
        for (int i = 0; i+1 < (int)path.size(); ++i)
            if ((path[i]==u && path[i+1]==v) ||
                (path[i]==v && path[i+1]==u))
                return true;
        return false;
    };
    auto wgt = [&](int u,int v){
        for (auto [x,w]: adj[u])
            if (x==v) return w;
        return INT_MAX;
    };

    // ASCII graph
    cout << "\nGraf (edge *…* = shortest path):\n\n";
    cout << "       [C]";
    cout << "--" << wgt(2,5) << "--[F]\n";
    cout << "      /    \\\n";
    cout << " [B]";
    if (onPath(1,2)) cout << "-*" << wgt(1,2) << "*-"; else cout << "--" << wgt(1,2) << "--";
    cout << "[C]       \\\n";
    cout << "  [A]";
    if (onPath(0,1)) cout << "-*" << wgt(0,1) << "*-"; else cout << "--" << wgt(0,1) << "--";
    cout << "[B]   \\\n";
    cout << "   |   ";
    cout << "[D]";
    if (onPath(3,4)) cout << "-*" << wgt(3,4) << "*-"; else cout << "--" << wgt(3,4) << "--";
    cout << "[E]";
    if (onPath(4,6)) cout << "-*" << wgt(4,6) << "*-"; else cout << "--" << wgt(4,6) << "--";
    cout << "[G]\n";

    return 0;
}
