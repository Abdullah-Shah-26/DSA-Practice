#include <iostream>
#include <vector>
using namespace std;

//! Undirected Weighted Graph - Adjacency List
//! store (vertex , edge weight) as pairs
int main()
{
    int vertex, edges;
    cout << "Enter the no of vertex & edges : ";
    cin >> vertex >> edges;

    // creating an adjacency list
    // TODO : an array of vectors and vector stores pairs
    vector<pair<int, int>> AdjList[vertex];

    int u, v, weight;
    for (int i = 0; i < edges; ++i)
    {
        cin >> u >> v >> weight;
        AdjList[u].push_back({v, weight});
        AdjList[v].push_back({u, weight});
    }
    // print the list
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < AdjList[i].size(); ++j)
            cout << AdjList[i][j].first << " " << AdjList[i][j].second << " ";

        cout << endl;
    }
}