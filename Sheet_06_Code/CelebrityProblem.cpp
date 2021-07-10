// code for Celebrity Problem using two pointers approach
#include<bits/stdc++.h>
using namespace std;
#define N 4
int CelebrityId(int n, int M[][N])
{
    int start = 0; 
    int end = n - 1; 
  
   // if start knows end, then start can’t be celebrity. so increment start, i.e. start++
   //else end cannot be celebrity so, end--;
    while (start < end) 
    { 
        if (M[start][end] == 1) 
            start++; 
        else
            end--; 
    } 
  // loop from 0 to n-1 and find the count of persons who knows the celebrity 
  //and the number of people whom the celebrity knows. if the count of persons who knows the celebrity is n-1 
  //and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.
    for (int i = 0; i < n; i++) 
    { 
        if ( (i != start) && (M[start][i] == 1 || M[i][start] == 0)) 
            return -1; 
    } 
  
    return start; 
} 
int main()
{  
	int arr[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		  {
		  cin>>arr[i][j];
	}
	}
	cout<<CelebrityId(4, arr);
	return 0;
}
