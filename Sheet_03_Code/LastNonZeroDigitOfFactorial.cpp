// first non zero digit from last of factorial of a number.
/*
this is the recursive formula used to find solution.
Let D(n) be the last non-zero digit in n!
If tens digit (or second last digit) of n is odd
    D(n) = 4 * D(floor(n/5)) * D(Unit digit of n) 
If tens digit (or second last digit) of n is even
    D(n) = 6 * D(floor(n/5)) * D(Unit digit of n)*/
#include<bits/stdc++.h>
using namespace std;
 
// Initialize values of last non-zero digit of
// numbers from 0 to 9
int digit[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
 
int lastNonzeroDigit(int n)
{
     if (n < 10)
        return digit[n];
 
    // Check whether tens (or second last) digit
    // is odd or even
    // If n = 375, So n/10 = 37 and (n/10)%10 = 7
    // Applying formula for even and odd cases.
    if (((n/10)%10)%2 == 0)
        return (6*lastNonzeroDigit(n/5)*digit[n%10]) % 10;
    else
        return (4*lastNonzeroDigit(n/5)*digit[n%10]) % 10;
}
 
// Driver code
int main()
{
    int n;
    cin>>n;
    cout << lastNonzeroDigit(n);
    return 0;
}
