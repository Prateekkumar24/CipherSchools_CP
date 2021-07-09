#include <bits/stdc++.h>
using namespace std;
 //Minimum Platform Required
 //using MultiMap
int MinPlatform(int arr[], int dep[], int n)
{
   
   
    multimap<int, bool> mp;
    for (int i = 0; i < n; i++) {
 
        // If its arrival then second value
        // of pair is '0' else '1'
        mp.insert(make_pair(arr[i], 0));
        mp.insert(make_pair(dep[i], 1));
    }
 
    int result = 0;
    int platneeded = 0;
 
   auto i = mp.begin();
 
   
    for (; i != mp.end(); i++) {
 
        // If its 0 then add 1 to platneeded
        // else minus 1 from platneeded.
        if ((*i).second == 0)
            platneeded++;
        else
            platneeded--;
 
        if (platneeded > result)
            result = platneeded;
    }
    return result;
}
 
// Driver code
int main()
{   int n;
    cin>>n;
    int arr[n]; 
    int dep[n];
	for(int i=0;i<n;i++)
	{  cout<<"Enter Arrival Time:"<<endl;
		cin>>arr[i];
		cout<<"Enter departure time:"<<endl;
		cin>>dep[i];
	 } 
    
    cout << "Minimum Number of Platform Required :"
         << MinPlatform(arr, dep, n);
    return 0;
}
