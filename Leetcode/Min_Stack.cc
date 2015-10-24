#include <stack>
#include <cassert>
using namespace std;
class MinStack {
public:
    void push(int x) {
        data_stack.push(x);
        int min = x;
        if(min_stack.size()!=0&&min_stack.top()<x)min = min_stack.top();
        min_stack.push(min);
    }

    void pop() {
        if(data_stack.size()==0||min_stack.size()==0)return;
        data_stack.pop();
        min_stack.pop();
    }

    int top() {
		assert(min_stack.size()>0&&data_stack.size()>0);
		return data_stack.top();
    }

    int getMin() {
		assert(min_stack.size()>0&&data_stack.size()>0);
		return min_stack.top();
    }
private:
	stack<int> data_stack;
	stack<int> min_stack;
};
