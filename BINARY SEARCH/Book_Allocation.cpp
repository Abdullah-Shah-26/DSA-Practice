class Solution {
    public: class Solution { // Overall TC = O(NlogN)
      int findPages(vector<int> &arr, int M) {
      int N = arr.size();
      
      // no of books < no of students - cannot distribute them
      if(M > N)
      return -1;
      
      int st = 0 , end = 0 , mid , ans;
      for(int i = 0 ; i < N ; i++)
      {
          st = max(st, arr[i]);
          end += arr[i];
      }
  // Think this problem like this - we want to distribute  some books among 2 students
  // I will be ensure that each of them will be allocated nearly similar no of pages with least difference
  
      // we will apply binary search and st = max value and end = total sum of pages
  while(st <= end) // TC = Ologn
  {
      mid= st + (end - st)/2;
      
      int pages = 0 , count = 1; // no of students
      // allocating pages
      for(int i = 0 ; i < N; i++) // tc = O(n)
      {
          pages += arr[i];
          if(pages > mid)//if one student is getting more than req pages give the rest to other student
          {
              count++;
              pages = arr[i]; 
          }
      }
      if(count <=  M) // if we can distribute 100 pages among 2 students then we can also distrubute then among 3 students too
      {
          ans = mid; // store the possible ans
          end = mid - 1; // and go left to find min possible ans so that there is least diff in no of pages each student get
      }
      else
      {
          st = mid + 1; 
      }
  }
  return ans;
      }
  };
  // ! Same approach - 
  bool isValid(vector<int>&arr, int n , int m , int maxallowedPages)
{ // tc = O(n)
    int stu = 1, pages = 0 ;
    for(int i = 0 ; i < n ; i++)
    {   
        // corner case ith book has pages > maxallowed pages we cannot allocate those maxallowed pages
        // to each student it will always be greater
        if(arr[i] > maxallowedPages)
        return false;
        
        if((pages + arr[i]) <= maxallowedPages)
        pages += arr[i];
        else{ // no of pages given to 1 student is exceeding maxallowedPages then 
            // we will need one more student
        stu++;
        pages = arr[i];
        }
         
        
    }
    return stu > m ? false : true;
}


int Solution::books(vector<int> &arr, int m) { 
    int sum = 0;
    int n = arr.size();
    
    // edge case - if student > books - its not possible to allocate atleast 1 book to each student
    if(m > n)
    {
        return -1;
    }
    
    int ans = -1;
    // find sum of arr
    for(int i = 0 ; i < arr.size(); i++)
    {
        sum+= arr[i];
    }
    // for optimizing Solution find range of values from max elem
    int maxelem = *max_element(arr.begin(),arr.end());
    
    
    // apply binary search on range of possible answers
    int st = maxelem , end = sum; 
    // problem is to find min possible max allowed pages that can be given to each student
    while(st <= end) // TC = O(nlog(range)) = O(nlogN)
    {
        // max allowed pages
        int mid =st + (end - st)/2;
        
        if(isValid(arr, n , m ,mid))// if ans is valid find min possible ans go left 
        {
            ans = mid;
            end = mid - 1;
        }
        else 
        {// ans is invalid - go right & increase the allowed limit of max pages 
            st = mid + 1;
        }
    }
    return ans;
} 

  