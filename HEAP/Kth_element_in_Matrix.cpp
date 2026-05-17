int kthSmallest(int mat[MAX][MAX], int n, int k)
{ // TC = O(klogn + n)
   vector <pair<int,pair<int,int>>>temp;
   for(int i = 0; i < n; i++)
   {
    // first push all elements of 0th col along with its (row,col) into vec
   // & push them in pq - min heap
   // pop the smallest element from heap and push its next elment of same 
   // row along with its (row,col) in heap do this until k = 0 we get kth smalest and store it in variable
       temp.push_back(make_pair(mat[i][0] ,make_pair(i,0)));
   }
  // create min heap - use iterators then - TC = O(N)
  priority_queue<pair<
  int,pair<int,int>>,
  vector<pair<int,pair<int,int>>>,
  greater<pair<int,pair<int,int>>>>
  p(temp.begin(),temp.end());
  // push data(value) , row , col in it
  
  int ans;
  pair<int, pair<int,int>> element;
  int i , j;
  
  while(k--)
  {
      element = p.top(); 
      p.pop();
      ans = element.first; // value
      i = element.second.first; // row no 
      j = element.second.second; // col no
      // 
      if(j + 1 < n)
      p.push(make_pair(mat[i][j+1],make_pair(i, j+1)));
  }
  return ans;
}
//!!_____________________________________________________________________________________________________________
//! method 2
// TC = O(Klogk)     SC = O(n^2 + k)
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  priority_queue<pair<int,pair<int,int>>,
  vector<pair<int, pair<int,int>>>,
  greater<pair<int, pair<int, int>>>>p;
  
// create a visited matrix to avoid pushing same element
bool visited[MAX][MAX] = {false};

// start by pushing the first element (0,0)
p.push({mat[0][0], {0,0}});
visited[0][0] = true; // mark as visited

int ans = -1;

while(k--)
{
    auto element = p.top();
    p.pop();
    ans = element.first; // value
    int i = element.second.first; // row no 
    int j = element.second.second; // col no 
    
    // popped wale ke  neeche wala heap mein daldo
    // Push elements below (i+1, j)
    // first check if it exist and not visited before
    if(i+1 < n && !visited[i+1][j])
    {
        p.push({mat[i+1][j], {i+1,j}});//push in heap
        visited[i+1][j] = true;// & mark as visited
    }
    // popped wale ke right wale heap mein dalo (i,j+1) &  
    // first check if its exist and isnt visited
    if(j+1 < n && !visited[i][j+1])
    {
        p.push({mat[i][j+1],{i,j+1}});
        visited[i][j+1] = true;
    }
    
   }
    return ans;
  }
//!________________________________________________________________________________________________
// Method 3 - BInary search approach sc = o(1)  TC = O(N*log(max - min))


 // counting no of elements <= mid 
 int count(int mat[MAX][MAX], int n , int mid ){
        
    int count = 0;
    int i = n-1,j = 0; // start from bottom left corner

while(i >= 0 && j < n)
{
// logic is agar koi column ka last element (us col ka sabse bada is smaller than mid)
// that means all the elements of that col are also smaller than mid
if(mat[i][j] <= mid )
{
    count += (i + 1);
    j++; // move to next col 
}
else
i--; // move up current element > mid hay 
}  
return count;
}


int kthSmallest(int mat[MAX][MAX], int n, int k)
{  
  //Binary Search Approach
  // k is treated as count of elements before an element 
  int st = mat[0][0]; // smallest element
  int end = mat[n-1][n-1]; // largest element
  
  while(st < end){
      
      int mid = st + (end - st)/2;
      int Count = count(mat, n , mid);
      // if count of elements < mid 
     // go to right 
      if(Count < k)
      {
          st = mid + 1;
      }
      // if count of elements > mid 
      // go to left
      else {
          end = mid;
      }
  }
  // when st == end == kth smallest element is held in start
  return st;
}
