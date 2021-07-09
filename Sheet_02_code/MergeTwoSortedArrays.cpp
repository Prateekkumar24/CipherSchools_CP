#include<bits/stdc++.h>
using namespace std;
 
// Function to merge arrays
void mergeSortedArrays(int arr1[], int arr2[], int size1, int size2)
{
    
    // map store key value pair in sorted order according to key
    //it uses red black tree internally
    
    map<int, bool> mp;
     
    // Insert value to map
    for(int i = 0; i < size1; i++)
    mp[arr1[i]] = true;
     
    for(int i = 0;i < size2;i++)
    mp[arr2[i]] = true;
     
    
    for(auto i: mp)
    cout<< i.first <<" ";
}
 
int main()
{   int size1,size2;
int arr1[size1], arr2[size2];
    cin>>size1;
   
    for(int i=0;i<size1;i++)
    {
    	cin>>arr1[i];
	}
	cout<<"Enter second sorted array"<<endl;
	 cin>>size2;
	for(int i=0;i<size2;i++)
	{
		cin>>arr2[i];
	}
    
    mergeSortedArrays(arr1, arr2, size1, size2);
     
    return 0;
}
