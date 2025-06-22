#include <iostream>
#include <vector>
using namespace std;

// Representation of Graph  _ Adjacency List
// Undirected Unweighted Graph

int main()
{

    int vertex, edges;
    cout << "Enter the no of Vertices & Edges : ";
    cin >> vertex >> edges;

    // creating adj list - an array containing vector as an element
    // array size = no of vertices
    // and in vector we store how many vertex a single vertex is pointing to
    vector<int> AdjList[vertex];
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    // Print the list
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < AdjList[i].size(); j++)
            cout << AdjList[i][j] << "  ";

        cout << endl;
    }
}