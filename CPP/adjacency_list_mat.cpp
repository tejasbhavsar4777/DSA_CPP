#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &mat, int i, int j) {
    mat[i][j] = 1; // Add edge from i to j
    mat[j][i] = 1; // Add edge from j to i (undirected graph)
}

void displayMatrix(vector<vector<int>> &mat) {
    int v = mat.size();
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;

    cout << "Enter the number of edges: ";
    cin >> e;

    // Initialize adjacency matrix with zeros
    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adjMatrix, u, v);
    }

    cout << "Adjacency Matrix:" << endl;
    displayMatrix(adjMatrix);

    return 0;
}
