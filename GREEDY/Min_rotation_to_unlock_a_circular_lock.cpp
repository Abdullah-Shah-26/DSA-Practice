class Solution {
  public:
    int rotationCount(long long R, long long D) {
        // code here
        int ans = 0;
        int first , second ;
        while(R)
        {
            first = R % 10; 
            second = D % 10;
            R /= 10;
            D /= 10;
            // clock / anticlockwise min of the 2 
            ans+=  min(abs(first - second), 10 - abs(first - second));
            
        }
        return ans;
    }
};