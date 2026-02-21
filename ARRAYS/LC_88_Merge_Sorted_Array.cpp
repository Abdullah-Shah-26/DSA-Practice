class Solution {
    public: //! TC = O(n+m)    // SC = O(1) - no extra space used
        void merge(vector<int>& A, int m, vector<int>& B, int n) {
            int idx = m + n -1 , i = m-1 , j = n-1;
    
            while(i >= 0 && j >= 0){
                 // jo bada hay wo jayega idx pe
                if(A[i] >= B[j]){  // if i is >= j
                A[idx] = A[i];    // in short we can write A[idx--] = A[i--]
                idx--;
                i--;
                }
                else { // j > i
                A[idx] = B[j];
                idx--;
                j--;
                }
            }
            // now even if i<0 but if j is not <0 the elements of B wont be copied and arranged in A
            // so we need another loop to copy B ke bache hue elements in A in backward fashion
            while(j>= 0){
                A[idx] = B[j];
                idx--;
                j--;
            }
        }
    };