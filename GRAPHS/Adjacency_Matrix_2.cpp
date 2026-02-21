#include <iostream>
#include <vector>
using namespace std;

// Representation of graph by adjacency Matrix - matrix of size vertex by vertex
//! Undirected Weighted Graph - store weight of edges in matrix

int main()
{
    int vertex, edges;
    cout << "Enter the no of Vertex and edges : ";
    cin >> vertex >> edges;

    // initializing whole matrix with 0 in each cell
    vector<vector<int>> AdjMat(vertex, vector<int>(vertex, 0));

    int u, v, weight;
    for (int i = 0; i < edges; i++) 
    {
        // u and v indicates ki 2 edges ka relation kya hay
        cin >> u >> v >> weight;
        // u pointing to vertex v && v pointing to vertex u -- since its an undirected graph
        AdjMat[u][v] = weight;
        AdjMat[v][u] = weight;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            cout << AdjMat[i][j] << "  ";

        cout << endl;
    }
}