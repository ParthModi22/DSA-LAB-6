#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph {
private:
    vector<vector<int> > adj_list;

public:
    Graph(int n) {
        adj_list.resize(n);
    }

    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
    }

   void bfs(int start) {
    unordered_set<int> visited;
    queue<int> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int j = 0; j < adj_list[node].size(); ++j) {
            int neighbor = adj_list[node][j];
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}


    void print_graph() {
        for (int i = 0; i < adj_list.size(); ++i) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (int j = 0; j < adj_list[i].size(); ++j) {
                cout << adj_list[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(4); // Create a graph with 4 vertices

    // Add edges
    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 2);
    graph.add_edge(2, 0);
    graph.add_edge(2, 3);
    graph.add_edge(3, 3);

    cout << "Graph:" << endl;
    graph.print_graph();

    cout << "\nBFS Traversal starting from vertex 2: ";
    graph.bfs(2); // Perform BFS traversal starting from vertex 2
    cout << endl;

    return 0;
}
