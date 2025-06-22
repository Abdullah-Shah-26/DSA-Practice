#include <iostream>
#include <vector>
using namespace std;

// Representation of graph by adjacency Matrix - matrix of size vertex by vertex
//! Directed Weighted Graph - Store weights of edges in matrix

int main()
{
    int vertex, edges;
    cout << "Enter the no of Vertex and edges : ";
    cin >> vertex >> edges;

    // initializing whole matrix with 0 in each cell
    vector<vector<int>> AdjMat(vertex, vector<int >(vertex, 0));

    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight ;
        // u pointing to vertex v - Since its Directed
        AdjMat[u][v] = weight;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            cout << AdjMat[i][j] << " ";

        cout << endl;
    }
}