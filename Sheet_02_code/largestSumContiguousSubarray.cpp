#include <bits/stdc++.h>
using namespace std;
/*better soln: use kadane algorithm:Explanation: 
The simple idea of Kadane’s algorithm is to look for all positive contiguous segments of the array
 (max_ending_here is used for this). 
 And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). 
Each time we get a positive-sum compare it with max_so_far and update max_so_far if it is greater than max_so_far 
*/
//kadane solution
/*int maxSubArraySum(int arr[], int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}*/
//optimized and effiecient solution enough to handle if all the element are negative
int LargestSumContigSubarr(vector<int> &vec,int &n) {
    if (n == 0) return 0;

    int maxSofar = vec[0], currMax = vec[0];
    for (int i = 1; i < n; i++) {
        currMax = max(vec[i], currMax + vec[i]);
        maxSofar = max(maxSofar, currMax);
    }   

    return maxSofar;
}
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	//int n=v.size();
	for(auto i=0;i<n;i++)
	    cin>>v[i];
	int maxsum=LargestSumContigSubarr(v,n);
	cout<<maxsum;
	return 0;
}
