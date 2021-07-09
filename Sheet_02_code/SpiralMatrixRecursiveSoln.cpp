#include<bits/stdc++.h>
using namespace std;
//// Function for printing matrix in spiral
// form  j: Start index of column
//  m, n: End index
// of matrix row and column 
//Recursive solution:

void print(vector<vector<int>> matrix, int stIndexRow, int j, int m, int n)
{
    // If startIndexRow or j lies outside the matrix
    if (stIndexRow>= m or j >= n)
        return;
 
    // Print First Row
    for (int p = j; p < n; p++)
        cout << matrix[stIndexRow][p] << " ";
 
    // Print Last Column
    for (int p = stIndexRow + 1; p < m; p++)
        cout << matrix[p][n - 1] << " ";
 
    // Print Last Row. if Last and
    // First Row are not same
    if ((m - 1) != stIndexRow)
        for (int p = n - 2; p >= j; p--)
            cout << matrix[m - 1][p] << " ";
 
    // Print First Column.  if Last and
    // First Column are not same
    if ((n - 1) != j)
        for (int p = m - 2; p > stIndexRow; p--)
            cout << matrix[p][j] << " ";
 
    print(matrix, stIndexRow + 1, j + 1, m - 1, n - 1);
}
int main()
{
	int R;
	int C;
	cin>>R>>C;

        vector<vector<int>> matrix(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> matrix[i][j];
            }
        }
 
    
    print(matrix, 0, 0, R, C);
    return 0;
}

 
