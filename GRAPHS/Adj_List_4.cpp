#include <iostream>
#include <vector>
using namespace std;
//! Directed Weighted Graph - Adjacency List
//! store (vertex , edge weight) as pairs
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    // creating a Adjlist - an array storing vector which stores pairs(vertex , edge weight)
    vector<pair<int, int>> AdjList[vertex];

    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        AdjList[u].push_back({u, weight});
    }
    // Print List
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < AdjList[i].size(); j++)
            cout << (AdjList[i][j].first) << " " << (AdjList[i][j].second) << " ";

        cout << endl;
    }
}