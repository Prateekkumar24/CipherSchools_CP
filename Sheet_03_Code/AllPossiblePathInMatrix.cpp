
// count all possible paths from top left to bottom right
 
#include <bits/stdc++.h>
using namespace std;
 
// Returns count of possible paths to reach cell at row and col from the topmost leftmost
// cell (cell at 1, 1)
int numberOfPaths(int row, int col)
{
    // If either given row number is first or given column
    // number is first
    if (row == 1 || col == 1)
        return 1;
 
    // If diagonal movements are allowed then the last
    // addition  required.
    return numberOfPaths(row - 1, col) + numberOfPaths(row, col- 1);
    // + numberOfPaths(row-1, col-1);
}
 
int main()
{  int m,n;
cin>>m>>n;
    cout << numberOfPaths(m, n);
    return 0;
}
