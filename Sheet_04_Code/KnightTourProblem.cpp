//code for Knight Tour Problem.
#include <bits/stdc++.h>
using namespace std;
 
#define N 5
 
/* check for validity of moves */
int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N
            && sol[x][y] == -1);
}

// function to find paths of movement of knight
int solveKThelper(int x, int y, int movei, int sol[N][N],
                int xMove[N], int yMove[N])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;
 
    // Try all next moves from the current coordinate 
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKThelper(next_x, next_y, movei + 1, sol,
                            xMove, yMove)
                == 1)
                return 1;
            else
                
               // backtrack
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}
 
// This function solves  problem using Backtracking. This function  uses solveKTUtil().
//  returns false if no complete tour is possible, 
// otherwise prints the tour.this function prints one of the feasible solutions. 
int solve()
{
    int sol[N][N];
 
    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
 
    // xMove[] and yMove[] define next move of Knight.
    
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
    // Since the Knight is initially at the first block
    sol[0][0] = 0;
 
    // Start from 0,0 and explore all tours using solveKThelper() 
    if (solveKThelper(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "Solution  not exist";
        return 0;
    }
    else{
	
        for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << sol[x][y];
        cout << endl;
    }
}
    return 1;
}
 

int main()
{
    solve();
    return 0;
}
 
