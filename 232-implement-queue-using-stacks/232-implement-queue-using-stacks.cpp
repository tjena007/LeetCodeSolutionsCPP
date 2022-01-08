class MyQueue {
public:
    stack<int> main;
    stack<int> temp;
    int front;
    MyQueue() {
        front = -1;
    }
    
    void push(int x) {
        if(main.size()==0){
            front = x;
        }
        main.push(x);
    }
    
    int pop() {
        if(main.size() == 0){
            return -1;
        }
        while(main.size()!=0){
            temp.push(main.top());
            main.pop();
        }
        int remove = temp.top();
        temp.pop();
        if(temp.size() == 0){
            front =-1;
            return remove;
        }
        front = temp.top();
        while(temp.size()!=0){
            main.push(temp.top());
            temp.pop();
        }
        return remove;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return main.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */