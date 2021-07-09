#include<bits/stdc++.h>
using namespace  std;
//find missing number.in naive approach wefind sum of n natural number - sum of element of given array.
//problem: this may cause integer overflow for large value of N.
//time complexity : O(n)
//optimized bit manipulation:a1^a2^...^an=a and a1^a2^....^a(n-1)=b;
//then a^b=an
int findmissing(int arr[], int n)
{
	//for xor of given element
	int x1=arr[0];
	//for xor of  number 1 to n 
	int x2=1;
	
	for(int i=1;i<n;i++)
	{
		x1=x1^arr[i];
	}
	for(int i=2;i<=n+1;i++)
	   {
	   	x2=x2^i;
	   }
	   cout<<(x1^x2);
	   return 0;
	
	
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
	return findmissing(arr,n);
	return 0;
}
