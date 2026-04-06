class Solution {
    public:
        int strStr(string haystack, string needle) {
            // C++ stl function that returns the position of first character if a string is found 
            // in other string else returns -1
    
            return haystack.find(needle);
        }
    };