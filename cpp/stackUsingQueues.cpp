// link = https://leetcode.com/problems/implement-stack-using-queues
class MyStack {
private:
    queue<int> S;
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> Q = S; // shallow copy
        while(!S.empty()) S.pop(); // clear queue-stack
        S.push(x);
        
        while(!Q.empty()){
            S.push(Q.front());
            Q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = S.front();
        S.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return S.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return S.empty();
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