#include<bits/stdc++.h>
using namespace std;
//majority elements in an array is element which appears more than size/2 times in an array
//naive: count appearance of element in array and if count increase half of size of array print element.
//efficient soln.: Moore's Voting algo.
int MajorityElement(int arr[],int n)
{
	int res=0,count =1;
	for(int i=1;i<n;i++)
	{
		if(arr[res]==arr[i])
		    count++;
		else
		   count--;
	
	if(count==0)
	{
		res=i;
		count=1;
	}}
	// to handle when no element is in majority 
	count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[res]==arr[i])
		     count++;}
		if(count <= n/2)
		   return -1;
	return arr[res];
	
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
	cout<<MajorityElement(arr,n);
	return 0;
}
