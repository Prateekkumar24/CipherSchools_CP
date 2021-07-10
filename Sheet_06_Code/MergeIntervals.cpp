//code to merge interval of overlapping interval

#include<bits/stdc++.h>
using namespace std;
 
bool comp(vector<int> a, vector<int> b) {
    return a[0]<b[0];
}


    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), comp);
        
        vector<vector<int>> res;
        
        //1. init
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        //2. count
        for(int i=0; i<intervals.size()-1; i++){
            if(end>=intervals[i+1][0]){
                //merged
                if(end<intervals[i+1][1])
                    end = intervals[i+1][1];
            } else {
			    // insert answer
                res.push_back({start,end});
                start = intervals[i+1][0];
                end = intervals[i+1][1];
            }
        }
        
        //3. insert last element
        res.push_back({start,end});
        return res;
    }

int main()
{
	int n;cin>>n;
	vector<vector<int>>arr(n,vector<int>(n));
	for(int i =0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		   cin>>arr[i][j];
	}
	vector<vector<int>>result = mergeIntervals(arr);
	cout<<"merged Intervals are:";
	for(int i =0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		   cout<<"{"<<result[i][j]<<" "<<"}";
	}
}
