// C++ code to reverse a stack using recursion
#include<bits/stdc++.h>
using namespace std;
 

stack<char> st;
 
// string to store result of reversed stack
string ns;
 
//  a recursive function that inserts an element at the bottom of a stack.
char insert_at_bottom(char x)
{
 
    if(st.size() == 0)
    st.push(x);
 
    else
    {
         
        // All items are held in Function Call
        // Stack until we reach end of the stack When the stack becomes empty, the  above if
        // part is executed and the item is inserted at the bottom
             
        char a = st.top();
        st.pop();
        insert_at_bottom(x);
 
        
        st.push(a);
    }
}
 
//  function to reverses the given stack using insert_at_bottom()
char reverse()
{
    if(st.size()>0)
    {
         
        // Hold all items in Function Call Stack until  reach end of the stack
        char x = st.top();
        st.pop();
        reverse();
         
        // Insert all the items held in Function Call Stack one by one from the bottom
        // to top. Every item is inserted at the bottom
        insert_at_bottom(x);
    }
}
 

int main()
{
     
   
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
     
 
    reverse();
    cout<<"Reversed Stack"
        <<endl;
     
    // storing values of reversed stack
    while(!st.empty())
    {
        char p=st.top();
        st.pop();
        ns+=p;
    }
    cout<<ns[3]<<" "<<ns[2]<<" "
        <<ns[1]<<" "<<ns[0]<<endl;
    return 0;
}
 
