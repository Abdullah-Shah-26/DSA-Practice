#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

//? The Celebrity Problem
// Last Updated : 25 Feb, 2025
// Given a square matrix mat[][] of size n x n, such that mat[i][j] = 1 means ith person knows jth person, the task is to find the celebrity. A celebrity is a person who is known to all but does not know anyone. Return the index of the celebrity, if there is no celebrity return -1.

// Note: Follow 0-based indexing and mat[i][i] will always be 1.

// Examples:  

// Input: mat[][] = [[1, 1, 0], 
//                              [0, 1, 0], 
//                              [0, 1, 1]]
// Output: 1
// Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity.


// Input: mat[][] = [[1, 1], 
//                             [1, 1]]
// Output: -1
// Explanation: The two people at the party both know each other. None of them is a celebrity.


// Input: mat[][] = [[1]]
// Output: 0

#include<iostream>     //! TC = O(n)  // SC = O(n) - stack 
#include<vector>
#include<stack>
using namespace std;

int getCelebrity(vector<vector<int>> arr){
    stack<int> s; //first push all val in stack then pop 2 values push the val which can probably be celebrity
    int n = arr.size();

    for(int i = 0; i<n; i++){
        s.push(i);

    }
    while(s.size() > 1){//atleast 2 elements in stack
        int i = s.top();
        s.pop();
        
        int j = s.top();
        s.pop();
    
            if(arr[i][j] == 0){ // i doesnt know j _ j cant be celeb - push i in stack 

                s.push(i);
            }
            else{          // i knows j - j can be celeb - push j in stack 
                s.push(j);
            }
    } // now we know that we are left with one element in stack -> check  whether its celebrity 

    int celeb = s.top();

    for(int i = 0; i <n ; i++){
        if((i != celeb) && (arr[i][celeb] == 0 || arr[celeb][i] == 1)){
            return -1;
        }
    }
    return celeb;

}
int main(){
    vector<vector<int>> arr = { {0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    int ans = getCelebrity(arr);

    cout<< " celebrity is : " << ans << endl;

    return 0;
}