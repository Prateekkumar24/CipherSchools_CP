
// code to find nearest smaller element(efficient sol)
#include <bits/stdc++.h>
using namespace std;
 
// Prints smaller elements on left side of every element
void PrevSmaller(int arr[], int n)
{
    stack<int> St;
 
    for (int i=0; i<n; i++)
    {
        // Keep removing top element from St while the top
        // element is greater than or equal to arr[i]
        while (!St.empty() && St.top() >= arr[i])
            St.pop();
 
        // If all elements in St greater than arr[i](print by asking interview what to return in that case)
        if (St.empty())
            cout << "  ";
        else  
            cout << St.top() << ", ";
 
        
        St.push(arr[i]);
    }
}
 
int main()
{  int n;
cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
    PrevSmaller(arr, n);
    return 0;
}
