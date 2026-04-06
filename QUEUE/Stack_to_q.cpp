//rohit nagi - code army
class MyStack { //! SC =  O(n) - 2 queues
    public:
        queue<int> q1;
        queue<int> q2;
    
        MyStack() {
            
        }
        //! TC of all ops = O(1)
        void push(int x) {
            // base cond both are khali
            if(empty())
            q1.push(x);
    
            // jis q mein element hoga usimein push hoga
            else if(q1.empty())
            q2.push(x);
    
            else
            q1.push(x);
        }
        
        int pop() {  //! TC = O(n)
            // kahi stack khali to nai hay
            if(empty())
            return 0;
        // agar q1 empty hay then elements are in q2 return q2 ka last element
            else if(q1.empty()){
                while(q2.size() > 1){ // jab tak q2 mein ek element (to be popped) nai bach jata put all elements in q1 
                    q1.push(q2.front());
                    q2.pop();  
                }
                int element = q2.front(); // store that one element in a varible and return 
                q2.pop();
                return element;
            }
            // q2 empty ho sakta hay - yaani elements are in q1 repeat the above steps & return q1 ka last element
            else
    
                while(q1.size() > 1){
    
                    q2.push(q1.front());
                    q1.pop();
                }
                int element = q1.front();
                q1.pop();
                return element;
        }
        
        int top() {
            // stack kahili ho
            if(empty())
            return 0;
    
            else if(q1.empty()){ //q1 khali hay means elements q2 mein honge 
                return q2.back();
            }
    
            else // q2 khali _ q1 mein elements honge
            return q1.back();  
        }
        
        bool empty() {
            return q1.empty() && q2.empty();
        }
    };
    