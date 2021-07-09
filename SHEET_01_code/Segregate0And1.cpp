#include<iostream>
using namespace std;
int segregateZerosAndOnes(bool arr[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=1)
		{
			swap(arr[i],arr[count]);
			count++;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{  
int n;
cin>>n;
	bool arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	 return segregateZerosAndOnes(arr,n);
	 return 0;
}
