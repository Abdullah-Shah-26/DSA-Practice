  #include <bits/stdc++.h>
  using namespace std;

  using ll = long long;
  using pii = pair<int, int>;
  using vi = vector<int>;
  using vll = vector<long long>;
  static const int MOD = 1e9 + 7;

  inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

  //! Using Iterative DFS

  int getDiameter(vector<vector<int>> &adj, int root){
    int n = adj.size();
    int diameter = 0;

    vector<int> heights(n, 0);

    stack<tuple<int,int,int>> st;
    st.push({root, -1, 0}); // Node, parent, state

    while(!st.empty()){
      auto [node, parent, state] = st.top();
      st.pop();

      if(state == 0){
        // First Time Visit 
        // Process Children First
        st.push({node, parent, 1});

        for(auto &nei : adj[node]){
          if(nei == parent) continue;

          st.push({nei, node, 0});
        }
      }
      else{
        // Second Time Visit
        // Children already processed
        // Compute Nodes ht and Findfind 2 children who are extremely far from node

        int max1 = 0, max2 = 0;

        for(auto &nei : adj[node]){
          if(nei == parent) continue;

          int h = heights[nei];

          if(h > max1){
            max2 = max1;
            max1 = h;
          }
          else if(h > max2){
            max2 = h;
          }
        }

        diameter = max(diameter, max1 + max2);
        heights[node] = max1 + 1;
      }
    }

    return diameter;
  }

  int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < n-1; i++){
      int u,v;
      cin >> u >> v;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    cout << getDiameter(adj, 1) << endl;
  }