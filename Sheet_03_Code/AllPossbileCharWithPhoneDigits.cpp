#include <bits/stdc++.h>
using namespace std;
 
//code to print all combination of characters from a given array of phone digits;
void Combinations(vector<char> keypad[],
                      int input[], string res, int index)
{
    // If  every digit of key is processed, return res
    if (index == -1) {
        cout << res << " ";
        return;
    }
 
    // Store current digit
    int digit = input[index];
 
    // Size of the list w.r.t. to current digit
    int len = keypad[digit].size();
 
    // One by one replace the digit with each character in the
    // corresponding list and proceed for next digit
    for (int i = 0; i < len; i++) {
        Combinations(keypad, input, keypad[digit][i] + res, index - 1);
    }
}
 

int main()
{
    vector<char> keypad[] =
    {
        {}, {},        // for 0 and 1 
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's'},
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z'}
    };
 
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++)
       cin>>input[i];
    Combinations(keypad, input, string(""), n - 1);
 
    return 0;
}
