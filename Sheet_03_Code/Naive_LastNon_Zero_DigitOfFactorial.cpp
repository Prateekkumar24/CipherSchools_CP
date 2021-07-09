#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{  int p=1;
	if(n<=0)
	   return p;
	else
	    return  n* fact(n-1);
	    //return factorial;
}

int lastNonZero(int n) //functn to calculate last non zero digit of 'n'
{
	if(n%10 != 0)
		return n%10;
	
	else
		return lastNonZero(n/10);
	}
int lastNonZeroDigit(int n)
    {
	    int fac=lastNonZero(fact(n));
		
		
	  cout<<fac;
}
int main()
{
	int n;
	cin>>n;
	//cout<<fact(n);
	return lastNonZeroDigit(n);
	
}
