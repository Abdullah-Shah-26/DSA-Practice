// A - Timeout / 
// Time Limit: 2 sec / Memory Limit: 1024 MiB

// ×
// It is prohibited to use generative AI in ongoing AtCoder contests. Please refer to the following rules for more details.

// AtCoder Rules against Generative AI - Version 20241206


// Score : 
// 150 points

// Problem Statement
// The elder of Takahashi Village falls asleep immediately. Specifically, if 
// S+0.5 seconds or more have passed since the elder was last tapped on the shoulder, the elder falls asleep.

// Currently, the elder is awake, and an attendant has just tapped the elder on the shoulder.

// From now on, the attendant will tap the elder's shoulder exactly 
// N times. The 
// i-th shoulder tap will be performed 
// T 
// i
// ​
//   seconds from now.

// Determine whether the elder remains awake continuously from now until 
// T 
// N
// ​
//   seconds later.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;    

int main()
{
    int N, S;
    cin >> N >> S;
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    T.push_back(0); // Add a dummy tap at time 0 to handle the first tap
    sort(T.begin(), T.end());   
}