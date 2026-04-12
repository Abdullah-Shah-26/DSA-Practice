#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(V + E) | SC = O(V)

//! DFS - Using HashMap

class Solution {
  public:
    void dfs(Node* node, Node* clonedNode, unordered_map<Node*,Node*> &m){
      for(auto &realNei : node->neighbors){

         if(!m.count(realNei)){ 
          Node* clonedNei = new Node(realNei->val);
          m[realNei] = clonedNei;

          clonedNode->neighbors.push_back(clonedNei);
          dfs(realNei, clonedNei, m);
        }
        else{
          clonedNode->neighbors.push_back(m[realNei]);
        }
      }
    }
    Node* cloneGraph(Node* node) {
      if(!node) return NULL;

      unordered_map<Node*, Node*> m; 
      // m[RealNode] -> ClonedNode  

      Node* clonedNode = new Node(node->val);
      m[node] = clonedNode;

      dfs(node, clonedNode, m);

      return clonedNode;
    }
};

//! DFS - Using Vector 

class Solution {
public:
  void dfs(Node* node, Node* clonedNode, vector<Node*> &m){
    for(auto &realNei : node->neighbors){
      
        if(m[realNei->val] == NULL){
        
        Node* clonedNei = new Node(realNei->val);
        m[realNei->val] = clonedNei;

        clonedNode->neighbors.push_back(clonedNei);
        dfs(realNei, clonedNei, m);
      } 
      else{
        clonedNode->neighbors.push_back(m[realNei->val]);
      }
    }
  }

  Node* cloneGraph(Node* node) {
    if(!node) return NULL;
    // m[RealNode->Val] -> ClonedNode  
    vector<Node*> m(101, NULL); 
    // Real Node value is used as idx where cloned pointer is stored

    Node* clonedNode = new Node(node->val);
    m[node->val] = clonedNode;

    dfs(node, clonedNode, m);

    return clonedNode;
  }
};

//! BFS 

void bfs(Node* root, Node* clonedRoot, vector<Node*> &m){
  
  queue<Node*> q;
  q.push(root); // Queue will only contain original nodes

  m[root->val] = clonedRoot;

  while(!q.empty()){
    Node* realNode = q.front();
    Node* clonedNode = m[realNode->val];
    q.pop();

    for(auto &realNei : realNode->neighbors){

      if(m[realNei->val] == NULL){ // Cloned Node Not Created

        Node* clonedNei = new Node(realNei->val);
        m[realNei->val] = clonedNei; // Mark as Created
        
        clonedNode->neighbors.push_back(clonedNei); // Connect in cloned graph

        q.push(realNei);
      }

      else{ // Already Created
        clonedNode->neighbors.push_back(m[realNei->val]);
      }
    }
  }
}

Node* cloneGraph(Node* node){
  if(!node) return NULL;

  vector<Node*> m(101, NULL);

  Node* clonedNode = new Node(node->val);

  bfs(node, clonedNode, m);

  return clonedNode;
}