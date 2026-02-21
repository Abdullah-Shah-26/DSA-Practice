//! TC = O(n)
string Solution::solve(string A){
    string B ="";
    vector<int>repeated(26,0); // for keeping track of repeated characters
    queue<char> q;
    
    for(int i = 0; i< A.size(); i++)
    {
        // if char is repeated 
        if(repeated[A[i]- 'a'] >= 1){
            
            repeated[A[i]- 'a']++; //repeatition ++
            // jo element q ke front mein hay and repeated hay  
            // it can't be a part of ans remove from q  
            // but before that check if q is empty
            while(!q.empty() && repeated[q.front() - 'a'] > 1)
            q.pop();
            
            // q empty ho gayi hay 
            if(q.empty())
            B+='#';
            
            else
            B+=q.front(); // front mein jo bacha will B mein add hoga
            
        
        }    
        
        else{ // non repeated hay
            
            repeated[A[i] - 'a']++; // repetition bada do and q mein push kardo since its not repeating
            q.push(A[i]);
            
            // q mein ek to bhi element hoga jo non repeated hay and it wont be empty
            while(repeated[q.front() - 'a'] >1)
            q.pop(); // repeated ko q se pop karinge
            
            B+= q.front(); // front wale ko B mein add kardenge
            
        }
        
    }
    return B;
}
