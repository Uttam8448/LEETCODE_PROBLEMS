class MyStack {
public:
    queue<int> q2;
    MyStack() {
        
    }     
    void push(int x) {
        q2.push(x);
        int i=0;
        while(i<q2.size()-1){
            int ele=q2.front();
            q2.pop();
            q2.push(ele);
            i++;
        }
    }
    
    int pop() {
         if(q2.empty())
            return -1;
        else{
            int ele=q2.front();
            q2.pop();
            return ele;
        }
    }
    
    int top() {
        return q2.front();
        
    }
    
    bool empty() {
        if(q2.empty())
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