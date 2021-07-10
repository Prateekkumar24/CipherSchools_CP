//balanced parenthesis using stack
#include <bits/stdc++.h>
using namespace std;
bool BalancedExp(string paren) {
   stack<char> st;
   char x;
   // iterate through string, if the current character is opening bracket like (, { or [, then push into stack
   for (int i=0; i<paren.length(); i++) {
      if (paren[i]=='('||paren[i]=='['||paren[i]=='{') {
         st.push(paren[i]);
         continue;
      }
      if (st.empty())
      return false;
      //the current character is closing bracket like ), } or ], then pop from stack, 
	  //and check whether the popped bracket is corresponding starting bracket of the current character, 
	  //then it is fine, otherwise that is not balanced.
         
      switch (paren[i]) {
      case ')':
         x = st.top();
         st.pop();
         if (x=='{' || x=='[')
            return false;
         break;
      case '}':
         x = st.top();
         st.pop();
         if (x=='(' || x=='[')
            return false;
         break;
      case ']':
         x = st.top();
         st.pop();
         if (x =='(' || x == '{')
            return false;
         break;
      }
   }
   return (st.empty());
}
int main() {
   string expresion;
   cin>>expression;
   if (BalancedExp(expresion))
      cout << " Balanced Parenthesis";
   else
      cout << " Not Balanced";
}
