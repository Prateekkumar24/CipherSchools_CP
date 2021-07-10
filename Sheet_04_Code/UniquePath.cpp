//program to count all possible paths from top left to bottom right
#include <bits/stdc++.h>
using namespace std;
 
//  count  possible paths to reach cell at
// row  and col  from the topmost leftmost cell (cell at 1, 1)
int numberOfPaths(int row, int col)
{
    // to store results
    int count[row][col];
 
    // Count of paths to reach any cell in first row
    for (int i = 0; i < row; i++)
        count[i][0] = 1;
 
    // Count of paths to reach any cell in first col
    for (int j = 0; j < col; j++)
        count[0][j] = 1;
 
    // Calculate count of paths for other cells in bottom-up manner
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++)
 
            //the last part the code calculates the total possible paths if the diagonal Move are allowed
            count[i][j] = count[i - 1][j] + count[i][j - 1]; //+ count[i-1][j-1];
    }
    return count[row - 1][col - 1];
}
 

int main()
{ int m,n;
cin>>m>>n;
    cout << numberOfPaths(m, n);
    return 0;
}
