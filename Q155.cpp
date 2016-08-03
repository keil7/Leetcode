class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
/*    ~MinStack() {
        while(!data.empty())
            data.pop();
        while(!min.empty())
            min.pop();
    }*/
    void push(int x) {
        data.push(x);
        if(min.empty()||x<=min.top())
            min.push(x);
        else
            min.push(min.top());
    }
    
    void pop() {
        data.pop();
        min.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> data;
    stack<int> min;
};
