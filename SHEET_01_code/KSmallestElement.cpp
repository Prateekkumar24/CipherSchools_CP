#include<bits/stdc++.h>
using namespace std;
//K smallest number from an array.
//naive: it will take O(nlogn) sort the array and print first K element array,
//efficient: using min-heap(priority queue) , O(logk+(n-k)*logk)
//create a priority_queue of k element.
//traverse from k+1th element and compare with top of heap and replace if k+1th element is smaller else ignore it.

int KSmallest(int arr[], int n, int k)
{
	priority_queue<int,vector<int>/*greater<int>*/>pq(arr,arr+k);
	for(int i=k;i<n;i++)
	{
		if(arr[i]<pq.top()) //for largest uncomment above and compareif a[i]>pq.top();
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}
	while(pq.empty()==false)
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
}
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	return KSmallest(arr,n,k);
	//return 0;
}
