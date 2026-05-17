class Solution{
    public:
      int heapHeight(int N, int arr[]){
            // edge case if size = 1 return ht 1
            if(N == 1)
            return 1;
            
            int height = 0;
            while(N > 1)
            {// kitne baar N ko divide kare taki 1 ajaein = ht 
                height ++;
                N /= 2;
                
            }
            return height;
        }
    };
    