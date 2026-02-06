class MyQueue {
public:
    stack<int> data;
    stack<int> temp;
    MyQueue() {
        
    }

    void push(int x) {
        data.push(x);
    }
    
    int pop() {
        int ret;
        while(!data.empty()) {
            temp.push(data.top());
            data.pop();
        }
        ret = temp.top();
        temp.pop();
        while(!temp.empty()) {
            data.push(temp.top());
            temp.pop();
        }
        return ret;
    }
    
    int peek() {
        int ret;
        while(!data.empty()) {
            temp.push(data.top());
            data.pop();
        }
        ret = temp.top();
        while(!temp.empty()) {
            data.push(temp.top());
            temp.pop();
        }
        return ret;
    }
    
    bool empty() {
        return data.empty();
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