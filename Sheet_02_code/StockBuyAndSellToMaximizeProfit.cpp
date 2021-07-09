#include<bits/stdc++.h>
using namespace std;
//stock buy and sell to maximize profit.
int maxProfit(int price[],  int n)
{
	int profit=0;
	for(int i=1;i<n;i++)
	       if(price[i]>=price[i-1])
	           profit+=price[i]-price[i-1];
	           
	return profit;
}
int main()
{   int n;
    cin>>n;
	int p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	cout<<maxProfit(p,n);
	return 0;
}
