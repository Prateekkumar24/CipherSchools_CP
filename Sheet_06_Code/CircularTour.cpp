//code for circular tour
#include<bits/stdc++.h>
using namespace std;
int Tour(int petrol[], int dist[],int n)
{
	int start=0,curr=0,prev=0;
	//traverse through array and compute curr petrol as curr left if it becomes negative intitialize start with i+1; 
	for(int i=0;i<n;i++)
	{
		curr +=petrol[i]-dist[i];
		if(curr<0)
		{
			start=i+1;
			prev=curr;
			curr=0;
		}
	}
	return ((curr+prev)>=0)?(start+1):-1;
}
int main()
{ int n;
cin>>n;
	int petrol[n], dist[n];
	for(int i=0;i<n;i++)
	{
		cin>>petrol[i];
	}
	cout<<"Enter distance:";
    for(int i=0;i<n;i++)
	{
		cin>>dist[i];
		}
	cout<<Tour(petrol, dist, n);
	return 0;	

}
