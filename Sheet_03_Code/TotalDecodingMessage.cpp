#include <bits/stdc++.h>
using namespace std;
 
// code to find ways in how many ways a
// string can be decoded of length greater than 0
// and starting with digit 1 and greater.

int countDecoding( string *digits, int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (digits[0] == "0")
        return 0;
 
    
    // Initialize count
    int count = 0;
 
    // If the last digit is not 0,
    // then last digit must add
    // to the number of words
    if (digits[n - 1] > "0")
        count = countDecoding(digits, n - 1);
 
    // If the last two digits form a number smaller
    // than or equal to 26, then consider
    // last two digits and recur
    if (digits[n - 2] == "1"
        || (digits[n - 2] == "2"
        && digits[n - 1] < "7"))
        count += countDecoding(digits, n - 2);
 
    return count;
}
 
// returns count of possible decodings by
// replacing 1 with A, 2 woth B, ... 26 with Z
int countWays(string *digits, int n)
{
    if (n == 0 || (n == 1 && digits[0] == "0"))
        return 0;
    return countDecoding(digits, n);
}
 

int main()
{
   
   int n;
   cin>>n;
   string digits[n];
   for(int i=0;i<n;i++)
   {
   	cin>>digits[i];
   }
    cout << "Count is " << countWays(digits, n);
    return 0;
}
