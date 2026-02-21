class Solution {
    public:
    // TC = O(n * 2^n) n size string->n-1 cuts -> 2^n partitions & checking pali for each string
    
    //! Logic to check if string is palindrome 
    bool isPalin(string s){
        string s2 = s; //copying s
        reverse(s2.begin(), s2.end()); //we"ll reverse s2 and campare with s1
    
        return s==s2; //true if both are equal
    }
    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans)
       {
        //base case
       if(s.size() == 0){// When the string becomes empty, it means we have found one valid partition.
        ans.push_back(partitions);//So we store partitions in ans.
        return;
       }
       //!Loop through the string & make partitions
       for(int i=0; i<s.size(); i++){
            string part = s.substr(0, i+1);
    
            if(isPalin(part)){ //If substring is a palindrome,we continue partitioning remaining part
    
                partitions.push_back(part);//Add the partition
    
                getAllParts(s.substr(i+1), partitions, ans);//Solve for remaining string
    
                partitions.pop_back();//backtracking_removing last partition from vec of string to store fresh set of partitions 
         }
        }
       }
        vector<vector<string>> partition(string s) {
            vector<vector<string>> ans;
            vector<string> partitions;
    
            getAllParts(s, partitions, ans);
            return ans;
        }
    };