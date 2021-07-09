#include<bits/stdc++.h>
using namespace std; 
 //equal partition subset sum: divide array into two parts such that sum of elements in both subsets are equal.
 
  bool isSubsetSum( int a[], int n, int sum){
        if (sum==0) return true;
        if (n==0) return false;
        if (a[n-1] > sum) return isSubsetSum(a, n-1, sum);
    // Case 1. Include the current item `arr[n]` in the subset and recur
    // for the remaining items `n-1` with the remaining total `sum-arr[n]
     // Case 2. Exclude the current item `A[n]` from the subset and recur for
    // the remaining items `n-1`
        return isSubsetSum(a, n - 1, sum)
                || isSubsetSum(a, n - 1, sum - a[n-1]);
    }
    int equalPartition(int n,int arr[]){
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        if(sum%2!=0)
           return 0;
        
        return isSubsetSum(arr,n,sum/2);
        
    }
    int main()
    {
    	int n, arr[n];
    	cin>>n;
    	for(int i=0;i<n;i++)
    	{
    		cin>>arr[i];
		}
		if(equalPartition(n,arr))
		  {
		    cout<<"yes";
		    }
		else
		   cout<<"No";
		   return 0;
	}

