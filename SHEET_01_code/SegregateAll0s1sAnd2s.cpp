#include <bits/stdc++.h>
using namespace std;
 
//  sort the array of 0s, 1s and 2s
void sortArr(int arr[], int n)
{
    int i, count0 = 0, count1 = 0, count2 = 0;
 
    // Count the number of 0s, 1s and 2s in the array
    for (i = 0; i < n; i++) {
        switch (arr[i]) {
        case 0:
            count0++;
            break;
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        }
    }
 
    // Update the array
    i = 0;
 
    // Store all the 0s in the beginning
    while (count0 > 0) {
        arr[i++] = 0;
        count0--;
    }
 
    // store all the 1s
    while (count1 > 0) {
        arr[i++] = 1;
        count1--;
    }
 
    // store all the 2s
    while (count2 > 0) {
        arr[i++] = 2;
        count2--;
    }
     
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    
}
 

int main()
{   int n;
    cin>>n;
    int arr[n] ;
    for(int i=0;i<n;i++)
          cin>>arr[i];
    sortArr(arr, n);
 
    return 0;
}
