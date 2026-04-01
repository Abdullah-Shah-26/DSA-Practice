#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Sparse Table -----------------------------------------------------------
//* TC = O(N Log N + Q)
//* SC = O(N Log N)

vector<vector<int>> st;
int LOG;

int *constructST(int arr[], int n) {
    LOG = 32 - __builtin_clz(n);
    st.assign(LOG, vector<int> (n));
    
    for(int i = 0; i < n; i++){
        st[0][i] = arr[i];
    }
    
    for(int j = 1; j < LOG; j++){
        for(int i = 0; i + (1 << j) <= n; i++){
            st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j - 1))]);
        }
    }
}

int RMQ(int segTree[], int n, int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

//! SegTree Approach ----------------------------------------------------------- 
//* TC = O(N + Q LogN)
//* SC = O(N)
void build(int i, int l, int r, int segTree[], int arr[]){ //!  O(N)
    if(l == r){
        segTree[i] = arr[l];
        return;
    }
    
    int mid = (l + r) >> 1;
    
    build(2*i+1,l,mid,segTree,arr);
    build(2*i+2,mid+1,r,segTree,arr);
    
    segTree[i] = min(segTree[2*i+1],segTree[2*i+2]);
}

int query(int qst, int qend, int i, int l, int r, int segTree[]){ //! O(Log N)
    
    if(r < qst || l > qend) return INT_MAX;
    
    if(l >= qst && r <= qend) return segTree[i];
    
    int mid = (l + r) >> 1;
    
    int left = query(qst, qend, 2*i+1, l, mid, segTree);
    int right = query(qst, qend, 2*i+2, mid+1, r, segTree);
    
    return min(left, right);
}

int *constructST(int arr[], int n) {
    int *segTree = new int[4*n];
    build(0,0,n-1,segTree,arr);
    return segTree;
}

int RMQ(int segTree[], int n, int a, int b) {
    return query(a,b,0,0,n-1,segTree);
}