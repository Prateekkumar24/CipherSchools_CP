//peak element in an array: a[i]is peak if a[i-1]<a[i]>a[i+1]
#include<bits/stdc++.h>
using namespace std;
//naive approach O(n)
/*int PeakElement(int arr[],int n)
{
	if (n == 1)
      return 0;
    if (arr[0] >= arr[1])
        return 0;
    if (arr[n - 1] >= arr[n - 2])
        return arr[n - 1];
 
    // check for every other element
    for (int i = 1; i < n - 1; i++) {
 
        // check if the neighbors are smaller
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return arr[i];
    }
	
 } */
 //efficient : O(logn)
 // A binary search based function
// that returns index of a peak element
int findPeakOptimized(int arr[], int low,
                 int high, int n)
{
    //  index of middle element
    // (low + high)/2
    int mid = low + (high - low) / 2;
 
    // Compare middle element with 
    // neighbours (if neighbours exist)
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return arr[mid];
 
    // If middle element is not peak and its
    // left neighbour is greater than it,
    // then left half  has a peak element
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeakOptimized(arr, low, (mid - 1), n);
 
    // If middle element is not peak and its
    // right neighbour is greater than it,
    // then right half  has a peak element
    else
        return findPeakOptimized(
            arr, (mid + 1), high, n);
}
int PeakElement(int arr[],int n)
{
	return findPeakOptimized(arr,0,n-1,n);
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
	cout<<PeakElement(arr,n);
	return 0;
 }
