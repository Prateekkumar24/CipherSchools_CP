#include<bits/stdc++.h>
using namespace std;

//  program to find all combinations that sum to a given value
	void helper(vector<vector<int>>& results, vector<int>& one_result, vector<int>& candidates, int start, int target)
	{   // if we get exact answer
		if (target == 0)
		{
			results.push_back(one_result);
		}

		if (target < 0)
		{
			return ;
		}
		// Recur for all remaining elements that
    // have value smaller than sum.

		for (int i = start; i < candidates.size(); i++)
		{  // Till every element in the array starting
        // from i which can contribute to the sum  add them to list
			one_result.push_back(candidates[i]);
			
			helper(results, one_result, candidates, i, target - candidates[i]);
			// Remove number from list (backtracking)
			one_result.pop_back();
		}
	}
	
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>> results;
		vector<int> one_result;
		 sort(candidates.begin(), candidates.end());
 
    // remove duplicates
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
		helper(results, one_result, candidates, 0, target);

		return results;
	}
	int main()
	{  int n;
	   cin>>n;
		vector<int>candidates(n);
		int target;
		for(int i=0;i<n;i++)
		{
			cin>>candidates[i];
		}
		cout<<"enter Target :";
		cin>> target;
		vector<vector<int>>res=combinationSum(candidates,  target);
		if (res.size() == 0) {
        cout << "No result";
        return 0;
    }
		   for (int i = 0; i < res.size(); i++) {
        if (res[i].size() > 0) {
            cout << " ( ";
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << ")";
        }
    }

		   
		return 0;
	}
