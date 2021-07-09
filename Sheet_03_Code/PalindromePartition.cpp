#include <bits/stdc++.h>
using namespace std;
 //number of min cuts required in a given string to find max palindrome string.
 //function to find palindrome in string
bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false; 
      i++;
      j--;
    }
    return true;
}
//function to find cut
int minPalPartion(string String, int i, int j)
{   //if this is true means given string is already palindrome so no cut required.
    if( i >= j || isPalindrome(String, i, j) )
      return 0;
    int ans = INT_MAX, count;
    //finding position to cut its a variant of matrix chain manipulation.
    for(int k = i; k < j; k++)
    {
      count = minPalPartion(String, i, k) +
        minPalPartion(String, k + 1, j) + 1;
  
      ans = min(ans, count);
    }
    return ans;
}
 
// Driver code
int main() {
    string str;
    cin>>str;
    cout << "Min cuts needed : "<<
      
      minPalPartion(str, 0, str.length() - 1) << endl;
    return 0;
}
