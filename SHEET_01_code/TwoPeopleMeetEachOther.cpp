#include<bits/stdc++.h>
using namespace std;
bool Meeting(int &p1,int &p2,int &s1,int &s2)
{
	if(p1>p2 && s1>s2)
	{
		return false;
	}
	if(p2>p1 && s2>s1)
	{
		return false;
	}
	int diffbtwntwo=abs(p1-p2);
	int diffspeedoftwo=abs(s1-s2);
	if(diffbtwntwo%diffspeedoftwo==0)
	{
		return true;
	}
	return false;
}

int main()
{
	int p1,p2,s1,s2;
	cin>>p1;
	cin>>p2;
	cin>>s1;
	cin>>s2;
	if (Meeting(p1,p2,s1,s2))
	    cout<<"They meet"<<endl;
	else
	    cout<<"They don't meet";
	return 0;
}
