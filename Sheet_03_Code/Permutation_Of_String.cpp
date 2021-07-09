#include<bits/stdc++.h>
using namespace std;
void permute(string S, int i=0)
{

	for(int j=i;j<S.length();j++)
	{
		swap(S[i],S[j]);
		permute(S,i+1);
		swap(S[i],S[j]);
	}
	if(i==S.length())
	
	{
	cout<<S<<" ";}
}
int main()
{
	string S;
	cin>>S;
	permute(S,0);
	return 0;
}
