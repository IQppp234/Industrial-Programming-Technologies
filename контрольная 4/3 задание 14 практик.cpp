#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class MinStack {
private:
    stack<int> data;   // основные элементы
    stack<int> mins;   // минимумы: mins.top() — минимум всего стека

public:
    void push(int x) {
        data.push(x);
        if (mins.empty() || x <= mins.top())
            mins.push(x);
        else
            mins.push(mins.top());
    }

    void pop() {
        if (data.empty()) throw runtime_error("Stack is empty");
        data.pop();
        mins.pop();
    }

    int top() const {
        if (data.empty()) throw runtime_error("Stack is empty");
        return data.top();
    }

    int getMin() const {
        if (mins.empty()) throw runtime_error("Stack is empty");
        return mins.top();
    }

    bool empty() const {
        return data.empty();
    }
};

int main() {
    MinStack st;
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "min = " << st.getMin() << endl; // 2
    st.pop();
    cout << "min = " << st.getMin() << endl; // 3
    st.pop();
    cout << "min = " << st.getMin() << endl; // 3
    st.pop();
    cout << "min = " << st.getMin() << endl; // 5
    cout << "empty = " << (st.empty() ? "true" : "false") << endl;
    st.pop();
    cout << "empty = " << (st.empty() ? "true" : "false") << endl;

    return 0;
}