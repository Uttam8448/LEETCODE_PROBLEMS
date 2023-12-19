class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }     
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            int ele=q1.front();
            q1.pop();
            q2.push(ele);
        }
        while(!q2.empty()){
            int ele=q2.front();
            q2.pop();
            q1.push(ele);
        }
    }
    
    int pop() {
         if(q1.empty())
            return -1;
        else{
            int ele=q1.front();
            q1.pop();
            return ele;
        }
    }
    
    int top() {
        return q1.front();
        
    }
    
    bool empty() {
        if(q1.empty())
            return 1;
        return 0;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */