#include <bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>> adj;
vector<int> color;

// Euler Tour
vector<int> tin, tout;
vector<int> euler;
int timer = 0;

// Subtree size
vector<int> subSize;

// Heavy child
vector<int> heavyChild;