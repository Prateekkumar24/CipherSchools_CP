//Kth smallest element in sorted matrix
#include <bits/stdc++.h>
using namespace std;
 
//  returns count of elements in matrix less than of equal to num
int ElementsGreaterOrEqual(int num, int n, int matrix[5][5]) {
    int ans = 0;
 
    for (int i = 0; i < n; i++) {
        // if num is less than the first element then no more element in matrix as it is sorted matrix
        if (matrix[i][0] > num) {
            return ans;
        }
        // if num is greater than last element, it is greater than all elements
        // in that row
        if (matrix[i][n - 1] <= num) {
            ans += n;
            continue;
        }
        // This contain the col index of last element in matrix less than of equal
        // to num
        int greater = 0;
        for (int jump = n / 2; jump >= 1; jump /= 2) {
            while (greater + jump < n &&
                   matrix[i][greater + jump] <= num) {
                greater += jump;
            }
        }
 
        ans += greater + 1;
    }
    return ans;
}
  
// reuturs kth smallest index in the matrix
int kthSmallest(int matrix[5][5], int n, int k) {
    
    //  do a binary search on answer based on the number of elements
    // our current element is greater than the elements in the matrix
    int l = matrix[0][0], r = matrix[n - 1][n - 1];
 
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int greatOrEqualMid = ElementsGreaterOrEqual(mid, n, matrix);
 
        if (greatOrEqualMid >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
 
int main() {
    int n = 5;
    int mat[5][5] = {
        {10, 20, 30, 40, 60},
        {15, 25, 35, 45, 63},
        {25, 29, 37, 48, 65},
        {32, 33, 39, 50, 70},
    };
    cout << "5th smallest element is: " << kthSmallest(mat, 4, 5);
    return 0;
}
