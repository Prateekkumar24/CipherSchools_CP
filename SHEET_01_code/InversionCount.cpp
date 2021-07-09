// Inversion count:Numbr of inversion required to make array sorted,
#include <bits/stdc++.h>
using namespace std;
 
int getInvCount(int arr[], int n)
{
    int invcount = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                invcount++;
 
    return invcount;
}
 
int main()
{   
  int n;
   cin>>n;
    int arr[n] ;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
    
    cout << "  Total number of inversions : "
         << getInvCount(arr, n);
    return 0;
}
 
