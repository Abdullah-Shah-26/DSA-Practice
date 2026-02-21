#include <iostream>
#include <vector>
using namespace std;

// Representation of graph by adjacency Matrix - matrix of size vertex by vertex
//! Directed unweighted Graph

int main()
{
    int vertex, edges;
    cout << "Enter the no of Vertex and edges : ";
    cin >> vertex >> edges;

    // initializing whole matrix with 0 in each cell
    vector<vector<bool>> AdjMat(vertex, vector<bool>(vertex, 0));

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        // u pointing to vertex v     -    Since its Directed ``````
        AdjMat[u][v] = 1;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            cout << AdjMat[i][j] << " ";

        cout << endl;
    }
}