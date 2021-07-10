//code to implement stack using two queues.
#include <bits/stdc++.h>
using namespace std;
 
class Stack
{
    queue<int> q1, q2;
 
public:
    // Insert an item into the stack
    void push(int data)
    {
        // Push the given item into the first queue
        q1.push(data);
    }
 
    // Remove the top item from the stack
    int pop()
    {
        // if the first queue is empty
        if (q1.empty())
        {
            cout << "Stack Underflow(empty)!!";
            exit(0);
        }
 
        // Move all elements except last from the first queue to the second queue
        int front;
        while (!q1.empty())
        {
            if (q1.size() == 1) {
                front = q1.front();
            }
            else {
                q2.push(q1.front());
            }
 
            q1.pop();
        }
 
        // Return the last element after moving all elements back to the first queue
       
        swap(q1,q2);
 
        return front;
    }
};
 
int main()
{  int n;
  cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    {
    	cin>>vec[i];
	}
 
    
    Stack st;
    for (int key: vec) {
        st.push(key);
    }
 
    for (int i = 0; i <= vec.size(); i++) {
        cout << st.pop() << endl;
    }
 
    return 0;
}
