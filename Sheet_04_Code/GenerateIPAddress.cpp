// code to generate all possible IP address from a given string
#include <bits/stdc++.h>

using namespace std;
bool isValid(string str)
{

   if(str.size()>3||str.size()==0) return false;
   
   if(str.size()>1 && str[0]=='0') return false; 
   
   if(str.size() && stoi(str)>255) return false;
   
   
   
   return true;
}
  
// Function to get all the valid ip-addresses
void GetAllValidIpAddress(int index, int dots,string temp,vector<string>& result,  string givenString)
{
  
   if(dots==3)
    {
       // pushing last partition after checking its validity
			
        if(isValid(givenString.substr(index)))
        {
       
            result.push_back(temp+givenString.substr(index));
            
        }
        return;
    }
	
    // placing the dot at every valid position
	
    for(int j=index; j<givenString.size() ;j++)
    {

	if( isValid(givenString.substr(index, j-index+1)))
	{
		temp.push_back(givenString[j]);
		temp.push_back('.');

	GetAllValidIpAddress(j+1, dots+1, temp, result, givenString);

	   // removing the dot after calling recur function 
	   // note that we don't remove the last digit that was placed in temp string 
	   //as we just have to change positions of dots only and not digits in string
		temp.pop_back();


        }
    }
    
    return;
}
  

int main()
{
    string Str;
    cin>>Str;
  
    // Fill result vector with all valid ip-addresses
    vector<string> result;
    GetAllValidIpAddress(0,0,  "", result,Str);
  
    // Print all the generated ip-addresses
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
}
