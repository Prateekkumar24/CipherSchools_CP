// Code to find duplicate parenthesis in a balanced expression
#include <bits/stdc++.h>
using namespace std;
 
bool Duplicateparenthesis(string str)
{
    stack<char> Stack;
     
    for (char ch : str)
    {
        // if current character is close parenthesis 
        if (ch == '}')
        {
            char top = Stack.top();
            Stack.pop();
 
            // stores the number of characters between a closing and opening parenthesis
            // if this count is less than or equal to 1 then the brackets are redundant else not
            int count = 0;
 
           
            while (top != '{')
            {
                count++;
                top = Stack.top();
                Stack.pop();
            }
            if(count < 1) {
				   return true;}
           
         }
        // push open parenthesis, operators and operands to stack
        else
            Stack.push(ch);
}
return 0;
           
}
 
int main()
{
    string str;
    cin>>str;
 
    if(Duplicateparenthesis(str))
      cout<<"There is duplicate";
    else
       cout<<"No duplicate ";
        
    return 0;
}
