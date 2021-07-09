#include<bits/stdc++.h>
using namespace std;
void helper(vector<string> &ans,string str, int open,int close,int n)
{  
	// if we use close==open then we may not be able to produce parantheses like ()() since open== close in first balanced only.
	if(close==n)
	{
		ans.push_back(str);
		return;
	}
	else
	  {
	  	if(open>close)
		  {
		  	helper(ans,str+')',open,close+1,n);
		  }
		  if(open<n)
		    {
			  helper(ans,str+'(',open+1,close,n);
	  }}
	
}
vector<string> Allparentheses(int n)
{  
	vector<string>ans;
	string str="";
	int open=0;int close=0;
	
	
	helper(ans,str,open,close,n);
	return ans;
	
}

int main()
{
	int n;
	cin>>n;
	vector<string>result;
	
	result=  Allparentheses(n);
	//to print result in order.
	sort(result.begin(),result.end());
	for(int i=0;i<result.size();++i)
	{
		cout<<result[i]<<"\n";
	}
	
  
	return 0;
}
