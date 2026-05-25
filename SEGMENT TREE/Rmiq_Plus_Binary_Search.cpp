#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<int>segTree;
    vector<int>arr;

    void buildSegTree(int i,int l,int r)
    {
      if(l == r)
      {
        segTree[i] = l;
        return;
      }

      int mid = (l+r)>> 1;
      buildSegTree(2*i+1,l,mid);
      buildSegTree(2*i+2,mid+1,r);

      int leftMaxIdx = segTree[2*i+1];
      int rightMaxIdx = segTree[2*i+2];

      if(arr[leftMaxIdx] >= arr[rightMaxIdx])
      {
        segTree[i] = leftMaxIdx;
      } 
      else 
      segTree[i] = rightMaxIdx;
    }
  // Binary Search On Range Query from L to Mid
    int RMIQ(int st,int end,int i,int l,int r)
    {
      if(l > end || r < st)
      return -1;

      if(st <= l && r <= end)
      {
        return segTree[i];
      }
      int mid = (l+r) >> 1;
      int leftMaxIdx = RMIQ(st,end,2*i+1,l,mid);
      int rightMaxIdx = RMIQ(st,end,2*i+2,mid+1,r);
      
      if(leftMaxIdx == -1)
      return rightMaxIdx;
      if(rightMaxIdx == -1)
      return leftMaxIdx;
      
      return (arr[leftMaxIdx] >= arr[rightMaxIdx]) ? leftMaxIdx : rightMaxIdx;  
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    vector<int>res;
    arr = heights;
    n = heights.size();
    segTree.resize(4*n,0);
    buildSegTree(0,0,n-1);
    for(auto &q:queries)
    {
      int minIdx = min(q[0],q[1]);
      int maxIdx = max(q[0],q[1]);

      if(minIdx == maxIdx){
      res.push_back(minIdx);
      continue;
      }
      else if(heights[maxIdx] > heights[minIdx])
      {
      res.push_back(maxIdx);
      continue;
      }
      int l = maxIdx +1;
      int r = n-1;
      int resIdx = 1e9;
      while(l <= r)
      {
        int mid = (l+r) >> 1;
        int idx = RMIQ(l,mid,0,0,n-1); //Returns the maxElement Idx in Range L to Mid
        if(heights[idx] > max(heights[minIdx],heights[maxIdx]))
        {
          resIdx = idx;
          r = mid-1;
        }
        else 
        {
          l = mid+1;
        }
      }
      if(resIdx == 1e9)
      res.push_back(-1);
      else 
      res.push_back(resIdx);
    }
    return res;
    }
};