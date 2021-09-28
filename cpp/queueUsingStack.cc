// link = https://leetcode.com/problems/implement-queue-using-stacks
class MyQueue {
private:
    stack<int> A, B;
public:
    MyQueue() {
    }
    
    void push(int x) {
        this->A.push(x);
    }
    
    int topUtil(bool remove) {
        int l;
        while(!this->A.empty()) {
            l = this->A.top();
            this->A.pop();
            this->B.push(l);
        }
        
        bool skip = remove;
        for(;!this->B.empty(); this->B.pop()) {
            if(skip) { skip = 0; continue; }
            this->A.push(this->B.top());
        }
        
        return l;
    }
    
    int pop() {
        return this->topUtil(1);
    }
    
    int peek() {
        return this->topUtil(0);
    }
    
    bool empty() {
        return this->A.empty();
    }
};

/**
O(1) amortized soln. from discussion forums
class Queue {
    stack<int> input, output;
public:

    void push(int x) {
        input.push(x);
    }

    void pop(void) {
        peek();
        output.pop();
    }

    int peek(void) {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool empty(void) {
        return input.empty() && output.empty();
    }
};
 */
 