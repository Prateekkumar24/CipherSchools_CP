// code to find next greater element for all array elements in same order as input.(using stack O(n))
#include <bits/stdc++.h>
using namespace std;
 
void printNextGreater(int arr[], int n)
{
    stack<int> s;
    int res[n];
    unordered_map<int, int> mp;
    s.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
 
// if stack is not empty, then pop an element from stack.If the popped element is smaller
// than next, then print the pair keep popping while elements are smaller and stack is not empty 
        while (s.empty() == false
               && s.top() < arr[i])
        {
            mp[s.top()]=arr[i];
            s.pop();
        }
 
        //push next element to stack to find next smaller for it 
        s.push(arr[i]);
    }
 
//for the remaining elements in stack do not have the next smaller element( return -1) 
    while (s.empty() == false)
    {
        mp[s.top()]= -1;
        s.pop();
    }
 
    for (int i = 0; i < n; i++)
        cout << mp[arr[i]] << endl;
}
 
int main()
{   int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    
    printNextGreater(arr, n);
    return 0;
}
