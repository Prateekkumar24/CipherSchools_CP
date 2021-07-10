//code to sort stack
#include <bits/stdc++.h>
using namespace std;
 
// Insert the given key into the sorted stack while maintaining its sorted order.
void sortedInsert(stack<int> &stack, int key)
{
    //  if the stack is empty or the key is greater than all elements in the stack
    if (stack.empty() || key > stack.top())
    {
        stack.push(key);
        return;
    }
 
    // remove the top element
    int top = stack.top();
    stack.pop();
 
    // recur for the remaining elements in the stack
    sortedInsert(stack, key);
 
    // insert the popped element back into the stack
    stack.push(top);
}
 
// Recursive method to sort a stack
void sortstack(stack<int> &stack)
{
    if (stack.empty()) {
        return;
}
    int top = stack.top();
    stack.pop();
 
    // recur for the remaining elements in the stack
    sortstack(stack);
 
    // insert the popped element back into the sorted stack
    sortedInsert(stack, top);
}
 
void printStack(stack<int> stack)
{
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
 
int main()
{
    vector<int> list = { 34, -1, 8, -7, 4};
 
    stack<int> stack;
    for (int i: list) {
        stack.push(i);
    }
 
    cout << "Stack before sorting: ";
    printStack(stack);
 
    sortstack(stack);
 
    cout << "Stack after sorting: ";
    printStack(stack);
 
    return 0;
}



