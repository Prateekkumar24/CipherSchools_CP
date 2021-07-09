#include<bits/stdc++.h>
using namespace std;
//Trapping Rain Water Problem
int getWater(vector<int> &arr, int n)
{
	int result=0;
	for(int i=1;i<n-1;i++)
	{   // find left max;
		int lMax=arr[i];
		for(int j=0;j<i;j++)
		     lMax=max(lMax,arr[j]);
	    //find right max
		     int rMax=arr[i];
        for(int j=i+1;j<n;j++)
           rMax=max(rMax,arr[j]);
           //update maximum water.
        result=result+(min(lMax,rMax)-arr[i]);
        cout<<result;
	}
}


int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	getWater(arr,n);
	return 0;
	
}
