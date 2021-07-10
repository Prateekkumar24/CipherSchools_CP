#include<bits/stdc++.h>
using namespace std;
#define N 5
    
/* function to check if a queen can be placed on board.
 this function is called when "col" queens are already placed in columns from 0 to col -1.
  So we need to check only left side for attacking queens */
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
  
    // Check this row on left side 
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
  
    // Check upper diagonal on left side 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
  
    // Check lower diagonal on left side 
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
  
    return true;
}
  
// function to find position
bool solveNQhelper(int board[N][N], int col)
{
    // base case: If all queens are placed then return true 
    if (col >= N)
        return true;
  
    //  consider this column and try placing this queen in all rows one by one 
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board
        
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
  
            // search to place rest of the queens 
            if (solveNQhelper(board, col + 1))
                return true;
  
            // If solution not found remove queen from board[i][col] (backtrack
            board[i][col] = 0; 
        }
    }
  
    // If the queen cannot be placed in any row then
    return false;
}
  
/* This function solves the N Queen problem using
   Backtracking with help of above helper function.this function prints one  of solutions*/
bool solveNQueens()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
  
    if (solveNQhelper(board, 0) == false) {
        cout<<"Solution  not found"<<endl;
        return false;
    }
  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<< board[i][j]<<" ";
        cout<<endl;
    }
    return true;
}
  

int main()
{
    solveNQueens();
    return 0;
}
