#include<bits/stdc++.h>
using namespace std;
 int convertToTitle(string &str) {
      int result=0;
      int i=0;
      while(i<str.length()){
          result=result*26+(str[i]-'A'+1);
         
          i++;
      }
        return result;
    }
int main()
{
	string str;
	cin>>str;
	cout<<convertToTitle(str);
	return 0;
}
