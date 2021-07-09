#include<bits/stdc++.h>
using namespace std;
//first and last occurrence of element:using upper_bound and lower_bound function.
//lower_bound: used to find first occurrence of elemenet and search accordingly.lower_bound(start,end+1,element to be searched)
//upper_bound: used to find last occurrence of an element. both takes O(logn) to search.
/*void FirstAndLast(int arr[],int n,int x)
{
	
 int 	first=lower_bound(arr,arr+n,x)-arr;
	int last=upper_bound(arr,arr+n,x)-arr-1;
	if(first==n)
	{
	    first=-1;
	    last=-1;}
	    
	    cout<< first<<" ";
	    cout<< last<<endl;
	  
}*/

//Method 2:

//using binary search
int firstOccur(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return firstOccur(arr, (mid + 1), high, x, n);
        else
            return firstOccur(arr, low, (mid - 1), x, n);
    }
    return -1;
}
 
int lastOccur(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return lastOccur(arr, low, (mid - 1), x, n);
        else
            return lastOccur(arr, (mid + 1), high, x, n);
    }
    return -1;
}
int main()
{
	int n;
	cin>>n;

	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int x;
	cin>>x;
	 cout<<"first occurrence:"<<" "<<
           firstOccur(arr, 0, n - 1, x, n)<<endl;
    cout<<"last occurrence:"<<" "<<
           lastOccur(arr, 0, n - 1, x, n);
	//FirstAndLast(arr,n,x);
	return 0;
}
