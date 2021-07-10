#include <bits/stdc++.h>
using namespace std;
//program to print all subsets of array
vector<vector<int>>AllSubset(vector<int> &nums)
{vector<vector<int>> ans;
    for (int i = 0; i < (1 << (nums.size())); i++)
    {  //  to store  current subset.
        vector<int> temp;
        for (int j = 0; j < nums.size(); j++)
        { //jth bit of I is set, then add the nums[i] to the temp array.
            if (i & (1 << j))
            {
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
    cout<<"{";
    cout<<"{"<<"}";
    for (auto x : ans)
    {  
        if(x.size()>0)
        cout<<"{";
        for (auto y : x)
        {
            if(y==x[x.size()-1])
            cout << y <<"}";
            else
            cout << y <<", "; 
        }
        cout <<" ";
    }
    cout<<"}";
	
}
int main()
{  int n;
cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
    	cin>>nums[i];
	}
 AllSubset(nums);
    return 0;
}
