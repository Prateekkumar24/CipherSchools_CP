#include<bits/stdc++.h>
using namespace std;
#define N 5
 
bool solveMaze(int maze[N][N],int row,int col,int solution[N][N])
{  
    // if (row, col is goal) return true
    if (
        row == N - 1 && col == N - 1
        && maze[row][col]== 1) {
        solution[row][col] = 1;
        return true;
    }
 
    // Check if maze[row][col] is valid
    if (row>=0 && col>= 0 && row<N && col<N && solution[row][col]==0 && maze[row][col]==1) {
          // Check if the current block is already part of solution path.   
          if (solution[row][col] == 1)
              return false;
       
        // mark row, col as part of solution path
        solution[row][col] = 1;
 
        /* Move forward in row direction */
        if (solveMaze(
                maze, row + 1, col, solution)
            == true)
            return true;
 
        /* If moving in row direction
        doesn't give solution then
        Move down in col direction */
        if (solveMaze(
                maze, row, col + 1, solution)
            == true)
            return true;
       
        /* If moving in row direction
        doesn't give solution then
        Move back in col direction */
        if (solveMaze(
                maze, row - 1, col, solution)
            == true)
            return true;
 
        /* If moving backwards in row direction
        doesn't give solution then
        Move upwards in col direction */
        if (solveMaze(
                maze, row, col - 1, solution)
            == true)
            return true;
 
        /* If none of the above movements
        work then BACKTRACK: then unmark  */
        solution[row][col] = 0;
        return false;
    }
 
    return false;
}
 

void printsol(int solution[N][N])
{
	cout<<"path is:"<<endl;
	int i,j;
	for(i=0;i<N;i++)
	  {
	    for(j=0;j<N;j++)
	   {
	   	cout<<solution[i][j];
	   }
	   cout<<endl;
	   }
}
void printmaze(int maze[N][N])
{ 
	cout<<"originzal maze:"<<endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<maze[i][j];
		}
		cout<<endl;
	}
}
int main()
{  
	int maze[N][N]=  {
	                        {1,0,1,0,0},
	                        {1,1,1,1,1},
	                        {0,1,0,1,0},
	                        {1,1,0,1,1},
	                        {0,1,1,1,1},
	                        };
 printmaze(maze);
int solution[N][N];
 int i,j;
  for( i=0;i<N;i++)
  {
  	for( j=0;j<N;j++)
  	{
  		solution[i][j]=0;
	  }
}
if(solveMaze(maze,0,0,solution))
   {
	 printsol(solution);
	 }
else
  cout<<"No Solution";
  return 0;
  return 0;}
