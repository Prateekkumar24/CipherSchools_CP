//code to find maximum of subarray of size k of given array using circular array
#include<bits/stdc++.h>
using namespace std;
//function to print max element
//use a dequeue of size k such that its first element will give max
void printMax(int arr[],int n,int k)
{
	deque<int>dq;
	for(int i=0;i<k;i++)
	{
		while(!dq.empty() && arr[i]>=arr[dq.back()])
		   dq.pop_back();
		dq.push_back(i);
	}
	for(int i=k;i<n;i++)
	{
		cout<<arr[dq.front()]<<" ";
		
	//pop element which isnot part of circular window
	while(!dq.empty() && dq.front()<=i-k)
	   dq.pop_front();
	   //push new element of window.
	while(!dq.empty() && arr[i]>=arr[dq.back()])
	    dq.pop_back();
	    dq.push_back(i);
}
cout<<arr[dq.front()]<<" ";
}
int main()
{
	int n,k;
	cin>>k;
	cout<<"enter size of array:";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	printMax(arr,n,k);
	return 0;
	
}
