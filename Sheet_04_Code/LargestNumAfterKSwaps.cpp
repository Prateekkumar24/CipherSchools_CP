#include <bits/stdc++.h>
using namespace std;
//  program to find maximum integer possible by doing
// at-most K swap operations on its digits.
void MaxNumAfterSwap(string num, int k, string& maxnum, int n){
   
   if (k == 0)
      return;
   for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
      	 // if digit at position i is less than digit
            // at position j, swap it and check for maximum
            // number so far and recurse for remaining swaps
         if (num[i] < num[j]) {
            swap(num[i], num[j]);
             // If current num is more than maximum so far
            if (num.compare(maxnum) > 0)
               maxnum = num;
              MaxNumAfterSwap(num, k - 1, maxnum, n);
            swap(num[i], num[j]);
         }
      }
   }
}

int main(){
   
   string str;
   cin>>str;
   int k;
   cin>>k;
   int size = str.length();
   string maxString = str;
   MaxNumAfterSwap(str, k, maxString, size);
   cout<<"The maximum number formed is: "<<maxString;

   return 0;
}
